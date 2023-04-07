#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100
// Стек для чисел
static double stack[STACK_SIZE];
static int top = -1;
void push(double n) {
    if (top + 1 < STACK_SIZE) {
        stack[++top] = n;
    } else {
        printf("error: stack is full\n");
        exit(111);
    }
}
double pop() {
    if (top != -1) {
        return stack[top--];
    } else {
        printf("error: stack is empty\n");
        exit(222);
    }
}

// Стек для операндов
static char stack_o[STACK_SIZE];
static int top_ = -1;
void push_o(char n) {
    if (top_ + 1 < STACK_SIZE) {
        stack_o[++top_] = n;
    } else {
        printf("error: stack is full\n");
        exit(111);
    }
}
char pop_o() {
    if (top_ != -1) {
        return stack_o[top_--];
    } else {
        return '\0';
    }
}

// Очистка стеков
void clear_stacks() {
    top = -1;
    top_ = -1;
}