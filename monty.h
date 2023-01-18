#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*===================================================================*/
/** Structs **/
/*===================================================================*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args - structure that will have the arguments from
 * main
 * @ac: the argument count
 * @file: file from main
 * @line_number: number of the current line in the file
 */
typedef	struct args
{
	int ac;
	char *file;
	unsigned int line_number;
} args_a;

/**
 * struct infr - extern data to be manipulated from
 * individual functions
 * @line: line from the file
 * @words: parsed tokens from line
 * @stack: pointer to the stack
 * @file: file pointer
 * @flag: flag to determine if its a stack or queue
 */
typedef struct infr
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *file;
	int flag: 3;
} infor_s;

extern infor_s infor;

#define INFOR_INIT {NULL, NULL, NULL, NULL, 0}

/*===================================================================*/
/** Handlers **/
/*===================================================================*/
void push_h(stack_t **stack, unsigned int line_number);
void pall_h(stack_t **stack, unsigned int line_number);
void pint_h(stack_t **stack, unsigned int line_number);
void pop_h(stack_t **stack, unsigned int line_number);
void swap_h(stack_t **stack, unsigned int line_number);
void add_h(stack_t **stack, unsigned int line_number);

/*===================================================================*/
/** Helpers **/
/*===================================================================*/
int count_ws(char *str);
char **tokens(char *str);
void run_cmd(args_a *args);
void (*get_func(char **parse))(stack_t **, unsigned int);

/*===================================================================*/
/** Cleaners **/
/*===================================================================*/
void release(char **args);
void release_all(int all);
void free_stack(char *stack);
