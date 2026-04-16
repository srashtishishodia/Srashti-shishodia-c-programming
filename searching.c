#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[100], n, i, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);
    if(result != -1)
        printf("Linear Search: Element found at index %d\n", result);
    else
        printf("Linear Search: Element not found\n");

    sort(arr, n);

    result = binarySearch(arr, n, key);
    if(result != -1)
        printf("Binary Search: Element found at index %d\n", result);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}