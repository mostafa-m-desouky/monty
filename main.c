#include "monty.h"

global_t vglo;

/**
 * ovgloVide - frees the global variables
 *
 * Return: void
 */
void ovgloVide(void)
{
	linkedVide(vglo.head);
	free(vglo.bfr);
	fclose(vglo.fd);
}

/**
 * start_vglo - int global varibal
 * @fd: file descriptor
 * Return: void
 */
void start_vglo(FILE *fd)
{
	vglo.ourLf = 1;
	vglo.currt = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = fd;
	vglo.bfr = NULL;
}

/**
 * check_input - check if the arg exist
 * @argc: the num of arg
 * @argv: all arg
 * Return: return name file
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - main function
 * @argc: the num of arg
 * @argv: all arg
 * Return: return 0
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	char *ourline[2] = {NULL, NULL};
	size_t size = 256;
	ssize_t nln = 0;

	fd = check_input(argc, argv);
	start_vglo(fd);
	nln = getline(&vglo.bfr, &size, fd);
	while (nln != -1)
	{
		ourline[0] = tokenStr(vglo.bfr, " \t\n");
		if (ourline[0] && ourline[0][0] != '#')
		{
			f = opcodeGet(ourline[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.currt);
				dprintf(2, "unknown instruction %s\n", ourline[0]);
				ovgloVide();
				exit(EXIT_FAILURE);
			}
			vglo.arg = tokenStr(NULL, " \t\n");
			f(&vglo.head, vglo.currt);
		}
		nln = getline(&vglo.bfr, &size, fd);
		vglo.currt++;
	}

	ovgloVide();

	return (0);
}
