#include <stdio.h>

int interpolationSearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        long long pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (pos < low || pos > high) return -1;

        if (arr[pos] == target) {
            return pos;
        }

        if (arr[pos] < target) {
            low = pos + 1;
        }

        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target1 = 50;
    int target2 = 25;

    int result1 = interpolationSearch(arr, n, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found.\n", target1);
    }

    int result2 = interpolationSearch(arr, n, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found.\n", target2);
    }

    return 0;
}
