#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char op) {
    if (top >= MAX_SIZE - 1) return;
    stack[++top] = op;
}

char pop() {
    if (top < 0) return '\0';
    return stack[top--];
}

char peek() {
    if (top < 0) return '\0';
    return stack[top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX_SIZE];
    int i, j;
    char ch;
    
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top > -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top > -1 && peek() == '(') {
                pop();
            }
        } else if (isOperator(ch)) {
            while (top > -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    
    while (top > -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[] = "a+b*(c^d-e)";
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix);
    return 0;
}
