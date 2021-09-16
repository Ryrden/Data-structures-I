#ifndef STACK_H
#define STACK_H

#include "cartas.h"
#include "util.h"
#define ERRO_STACK (-300)

typedef struct stack_st STACK;

STACK *create_stack();
boolean stack_empty(const STACK *stack);
int stack_size(const STACK *stack);
int stack_stackup(STACK *stack, void *item);
void *stack_top(const STACK *stack);
void *stack_unstack(STACK *stack);
boolean stack_erase(STACK **stack);

#endif //STACK_H