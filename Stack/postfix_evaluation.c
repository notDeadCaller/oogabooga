#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top >= MAX_SIZE - 1) return;
    stack[++top] = data;
}

int pop() {
    if (top < 0) return 0;
    return stack[top--];
}

int evaluate(char op, int op2, int op1) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return 1;
    }
    return 0;
}

int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int op2 = pop();
            int op1 = pop();
            push(evaluate(exp[i], op2, op1));
        }
    }
    return pop();
}

int main() {
    char exp[] = "231*+9-";
    printf("Postfix Expression: %s\n", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}
