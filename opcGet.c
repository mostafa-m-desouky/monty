#include "monty.h"

/**
 * opcodeGet - get the code must be excuted
 * @opc: opcode
 * Return: return a ptr
 * amine mohamed
 */
void (*opcodeGet(char *opc))(stack_t **stk, unsigned int nmLn)
{
	instruction_t instruct[] = {
		{"push", node_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"mul", stack_mul},
		{"rotr", stack_rotr},
                {"rotl", stack_rotl},
		{"swap", stack_swap},
		{"add", stack_add},
		{"nop", stack_nop},
		{"sub", stack_sub},
		{"div", stack_div},
		{NULL, NULL}
	};
	int l;

	for (l = 0; instruct[l].opcode; l++)
	{
		if (compare_str(instruct[l].opcode, opc) == 0)
			break;
	}

	return (instruct[l].f);
}
