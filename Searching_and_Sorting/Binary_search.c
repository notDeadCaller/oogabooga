#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target1 = 25;
    int target2 = 12;

    int result1 = binarySearch(arr, 0, n - 1, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found.\n", target1);
    }

    int result2 = binarySearch(arr, 0, n - 1, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found.\n", target2);
    }

    return 0;
}
