#include <stdio.h>
int factorial(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}
int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r, choice;

    printf("1. Permutation\n");
    printf("2. Combination\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Enter value of r: ");
    scanf("%d", &r);

    if (r > n)
    {
        printf("Invalid input! r should be less than or equal to n.");
    }
    else
    {
        if (choice == 1)
        {
            printf("Permutation = %d", permutation(n, r));
        }
        else if (choice == 2)
        {
            printf("Combination = %d", combination(n, r));
        }
        else
        {
            printf("Invalid choice");
        }
    }

    return 0;
}


