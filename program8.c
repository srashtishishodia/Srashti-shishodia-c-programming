#include <stdio.h>

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", fromPeg, toPeg);
        return;
    }
    towerOfHanoi(n-1, fromPeg, auxPeg, toPeg);

    printf("Move disk %d from %c to %c\n", n, fromPeg, toPeg);
    towerOfHanoi(n-1, auxPeg, toPeg, fromPeg);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Sequence of moves:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); 

    return 0;
}