#include "stack.h"
#include "cartas.h"
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    CARD *card;
    NODE *previous;
};

struct stack_st {
    NODE *top;
    int size;
};

static void stack_remove_tudo(STACK *const *stack);

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
    if (stack != NULL) {
        return stack->size == 0;
    }
    return ERRO_STACK;
}

boolean stack_full(const STACK *stack) {
    if (stack != NULL) {
        return FALSE;
    }
    return ERRO_STACK;
}

int stack_size(const STACK *stack) {
    if (stack != NULL) {
        return stack->size;
    }
    return ERRO_STACK;
}

int stack_stackup(STACK *stack, CARD *card) {

    if (stack == NULL)
        return ERRO;

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL)
        exit(EXIT_FAILURE);

    newNode->card = card;
    newNode->previous = stack->top;
    stack->top = newNode;
    stack->size++;
    return TRUE;
}

CARD *stack_top(const STACK *stack) {
    if ((stack != NULL) && (!stack_empty(stack))) {
        return stack->top->card;
    }
    return NULL;
}

CARD *stack_unstack(STACK *stack) {
    if ((stack == NULL) || (!stack_empty(stack)))
        return NULL;

    NODE *unstacked = stack->top;
    CARD *card = stack->top->card;
    stack->top = stack->top->previous;
    unstacked->previous = NULL;
    free(unstacked);
    unstacked = NULL;
    stack->size--;
    return card;
}

boolean stack_apagar(STACK **stack) {
    if ((*stack != NULL) && (!stack_empty(*stack))) {
        stack_remove_tudo(stack);
        free(*stack);
        *stack = NULL;
        return TRUE;
    }
    return FALSE;
}

static void stack_remove_tudo(STACK *const *stack) {
    while ((*stack)->top != NULL) {
        stack_remove_top(stack);
    }
}

static void stack_remove_top(STACK *const *stack) {
    NODE *temporaryNode;
    temporaryNode = (*stack)->top;
    (*stack)->top = (*stack)->top->previous;
    card_erase(&temporaryNode->card);
    temporaryNode->previous = NULL;
    free(temporaryNode);
    temporaryNode = NULL;
}