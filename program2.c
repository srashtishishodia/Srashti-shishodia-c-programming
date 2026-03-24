#include <stdio.h>
void increase(int *ptr) {
    *ptr = *ptr + 1; 
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);  
    increase(&num);   
    printf("Number after increment: %d\n", num);
    
    return 0;
}