#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i;
    int *arr;

    printf("Enter initial size of array (n1): ");
    scanf("%d", &n1);

    arr = (int*) malloc(n1 * sizeof(int));
    if(arr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n1);
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of extra elements (n2): ");
    scanf("%d", &n2);

    arr = (int*) realloc(arr, (n1 + n2) * sizeof(int));
    if(arr == NULL) {
        printf("Memory not reallocated.\n");
        return 1;
    }

    printf("Enter %d new elements:\n", n2);
    for(i = n1; i < n1 + n2; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array after expansion:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);

    return 0;
}