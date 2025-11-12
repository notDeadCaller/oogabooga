#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

long long tailFactorial(int n, long long accumulator) {
    if (n == 0 || n == 1) {
        return accumulator;
    }
    return tailFactorial(n - 1, accumulator * n);
}

long long factorialTail(int n) {
    return tailFactorial(n, 1);
}

int main() {
    int num = 5;
    printf("Finding factorial of %d:\n", num);
    printf("Recursive result: %lld\n", factorial(num));
    printf("Tail Recursive result: %lld\n", factorialTail(num));
    return 0;
}
