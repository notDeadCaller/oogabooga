#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int tailFibonacci(int n, int a, int b) {
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    return tailFibonacci(n - 1, b, a + b);
}

int fibonacciTail(int n) {
    if (n == 0) return 0;
    return tailFibonacci(n - 2, 1, 1);
}

void printFibonacci(int count) {
    printf("Fibonacci Series (Recursive): ");
    for (int i = 0; i < count; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    printf("Fibonacci Series (Tail Recursive): ");
    for (int i = 0; i < count; i++) {
        if (i == 0) {
             printf("%d ", 0);
        } else if (i == 1) {
             printf("%d ", 1);
        } else {
             printf("%d ", fibonacciTail(i));
        }
    }
    printf("\n");
}

int main() {
    printFibonacci(8);
    return 0;
}
