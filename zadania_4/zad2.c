#include <stdio.h>

int searchBinary(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return searchBinary(arr, left, mid - 1, x);
        }

        return searchBinary(arr, mid + 1, right, x);
    }

    return -1;
}

int main() {
    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 23;

    int result = searchBinary(array, 0, n - 1, x);
    if (result == -1) {
        printf("Element %d was not found in the array.\n", x);
    } else {
        printf("Element %d was found at index %d.\n", x, result);
    }
    return 0;
}