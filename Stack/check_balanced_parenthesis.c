#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation using an array
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) return;
    stack[++top] = item;
}

char pop() {
    if (top < 0) return '\0';
    return stack[top--];
}

int isPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int checkBalanced(char* exp) {
    for (int i = 0; i < strlen(exp); i++) {
        char symbol = exp[i];

        if (symbol == '(' || symbol == '{' || symbol == '[') {
            push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (top < 0) return 0; // Closing parenthesis without an opening one
            
            char popped_char = pop();
            if (!isPair(popped_char, symbol)) {
                return 0; // Mismatch
            }
        }
    }
    
    return top == -1; // True if stack is empty (all opened were closed)
}

int main() {
    char exp1[] = "{[()]}";
    char exp2[] = "{[(])}";
    char exp3[] = "((a+b)-c)";

    printf("Expression 1: %s -> %s\n", exp1, checkBalanced(exp1) ? "BALANCED" : "NOT BALANCED");
    printf("Expression 2: %s -> %s\n", exp2, checkBalanced(exp2) ? "NOT BALANCED" : "NOT BALANCED");
    printf("Expression 3: %s -> %s\n", exp3, checkBalanced(exp3) ? "BALANCED" : "NOT BALANCED");
    
    return 0;
}
