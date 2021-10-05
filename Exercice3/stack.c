#include "stack.h"
#include "cartas.h"
#include <stdlib.h>
#include <string.h>

typedef struct node_st NODE;

struct node_st {
    void *item;
    int *requiredDataMemoryBlock;
    NODE *previous;
};

struct stack_st {
    NODE *top;
    int size;
};

static void stack_remove_all(STACK *const *stack);

static void stack_remove_top(STACK *const *stack);

STACK *create_stack() {
    STACK *stack = (STACK *)malloc(sizeof(STACK));

    if (stack == NULL)
        exit(EXIT_FAILURE);

    stack->top = NULL;
    stack->size = 0;

    return stack;
}

boolean stack_empty(const STACK *stack) {
    if (stack != NULL)
        return stack->size == 0;

    return ERRO_STACK;
}

int stack_size(const STACK *stack) {
    if (stack != NULL)
        return stack->size;

    return ERRO_STACK;
}

int stack_stackup(STACK *stack, void *item) {

    if (stack == NULL)
        return ERRO;

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
        exit(EXIT_FAILURE);

    memcpy(newNode->requiredDataMemoryBlock, item, size_t(item));
    newNode->item = item;
    newNode->previous = stack->top;
    stack->top = newNode;
    stack->size++;
    return TRUE;
}

void *stack_top(const STACK *stack) {
    if ((stack != NULL) && (!stack_empty(stack)))
        return stack->top->item;

    return NULL;
}

void *stack_unstack(STACK *stack) {
    if ((stack == NULL) || (stack_empty(stack)))
        return NULL;

    NODE *unstacked = stack->top;
    void *item = stack->top->item;
    stack->top = stack->top->previous;
    unstacked->previous = NULL;
    free(unstacked);
    unstacked = NULL;
    stack->size--;
    return item;
}

boolean stack_erase(STACK **stack) {
    if ((*stack != NULL) && (!stack_empty(*stack))) {
        stack_remove_all(stack);
        free(*stack);
        *stack = NULL;
        return TRUE;
    }
    return FALSE;
}

static void stack_remove_all(STACK *const *stack) {
    while ((*stack)->top != NULL)
        stack_remove_top(stack);
}

static void stack_remove_top(STACK *const *stack) {
    NODE *temporaryNode;
    temporaryNode = (*stack)->top;
    (*stack)->top = (*stack)->top->previous;
    free(temporaryNode->item);
    temporaryNode->item = NULL;
    temporaryNode->previous = NULL;
    free(temporaryNode);
    temporaryNode = NULL;
}