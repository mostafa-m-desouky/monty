#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list
 * @n: number
 * @prev: pointe to the prev ele
 * @next: pointe to the next ele
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - contains global varibale.
 * @ourLf: is stack or queue
 * @fd: to descripe the file
 * @bfr: the text
 * @currt: current line
 * @arg: the secod para
 * @head: dbl linked ls
 */
typedef struct globals
{
	int ourLf;
	stack_t *head;
	FILE *fd;
	char *bfr;
	unsigned int currt;
	char  *arg;
} global_t;

/**
 * struct instruction_s - linked list for opcode
 * @opcode: opcode
 * @f: handle opcod
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;
/*don’t do anything*/
void node_push(stack_t **db, unsigned int cl);
void stack_rotr(stack_t **db, unsigned int cl);
void stack_rotl(stack_t **db, unsigned int cl);
void stack_pall(stack_t **db, unsigned int cl);
void stack_pint(stack_t **db, unsigned int cl);
void stack_mul(stack_t **db, unsigned int cl);
void stack_pop(stack_t **db, unsigned int cl);
void stack_swap(stack_t **db, unsigned int cl);
void stack_add(stack_t **db, unsigned int cl);
void stack_nop(stack_t **db, unsigned int cl);
void stack_sub(stack_t **db, unsigned int cl);
void stack_div(stack_t **db, unsigned int cl);
/*get function*/
void (*opcodeGet(char *opc))(stack_t **stk, unsigned int nmLn);

/*copy of some funct*/
int seaRch(char *str, char chart);
/* serching for char instring*/
char *tokenStr(char *str, char *delim);
/*parsing string*/
void *realloc_copy(void *pr, unsigned int odSz, unsigned int nwSz);
/* relloce the space located*/
void *calloc_copy(unsigned int nb, unsigned int sz);
/* copy of callc functions*/
int compare_str(char *str1, char *str2);

/*free linked list*/
void ovgloVide(void);

/* do some*/
stack_t *addToEnd(stack_t **debut, const int nber);
stack_t *NodeAdd(stack_t **debut, const int n);
void linkedVide(stack_t *debut);



#endif
