#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 5, 15, 20, 3, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target1 = 20;
    int target2 = 99;

    int result1 = linearSearch(arr, n, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found.\n", target1);
    }

    int result2 = linearSearch(arr, n, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found.\n", target2);
    }

    return 0;
}
