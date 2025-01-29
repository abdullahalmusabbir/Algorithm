#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


struct Stack {
    int top;
    char items[MAX_SIZE];
};


int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}


void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}


char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}


int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1;
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        } else if (current == '(') {
            push(&stack, current);
        } else if (current == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) >= getPrecedence(current)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }

        i++;
    }


    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

