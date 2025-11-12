#include <stdio.h>

int findOddOccurrence(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = result ^ arr[i];
    }
    return result;
}

int main() {
    int arr[] = {4, 3, 3, 4, 4, 4, 5, 5, 8, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int oddNumber = findOddOccurrence(arr, n);
    printf("The number occurring an odd number of times is: %d\n", oddNumber);

    return 0;
}

