#include <stdio.h>
#include <stdlib.h>

void menu(int *choice);
void input(int arr[], int *n);
void display(int arr[], int n);
int sum_array(int arr[], int n);
float avg_array(int arr[], int n);
int min_array(int arr[], int n);
int max_array(int arr[], int n);

int main() {
    int data[100], ch, n = 0;

    while(1) {
        menu(&ch);

        switch(ch) {
            case 1:
                input(data, &n);
                break;
            case 2:
                display(data, n);
                printf("Sum = %d\n", sum_array(data, n));
                break;
            case 3:
                display(data, n);
                printf("Average = %.2f\n", avg_array(data, n));
                break;
            case 4:
                display(data, n);
                printf("Minimum = %d\n", min_array(data, n));
                break;
            case 5:
                display(data, n);
                printf("Maximum = %d\n", max_array(data, n));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}

void menu(int *choice) {
    printf("1. Input array\n");
    printf("2. Sum of array\n");
    printf("3. Average of array\n");
    printf("4. Minimum element\n");
    printf("5. Maximum element\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
}

void input(int arr[], int *n) {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", n);
    printf("Enter elements: ");
    for(i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}

void display(int arr[], int n) {
    int i;
    printf("Array elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int sum_array(int arr[], int n) {
    int sum = 0, i;
    for(i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

float avg_array(int arr[], int n) {
    return (float)sum_array(arr, n) / n;
}

int min_array(int arr[], int n) {
    int min = arr[0], i;
    for(i = 1; i < n; i++)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

int max_array(int arr[], int n) {
    int max = arr[0], i;
    for(i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}