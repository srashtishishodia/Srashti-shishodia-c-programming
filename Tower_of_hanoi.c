#include<stdio.h>
void toh(int n, char src, char aux, char dest) {
    if(n > 0) {
        toh(n-1,src,dest,aux);
        printf("%c -> %c\t",src,dest);
        toh(n-1,aux,src,dest);
    }
}

int main() {
    int n;
    printf("Enter total no.s of discs :");
    scanf("%d",&n);
    toh(n,'A','B','C');
}

struct data {
    int dd,mm,yy;
};

int main() {
    struct data dob;
    char month[12][3] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    printf("Enter dob(day-month-year)");
    scanf("%d-%d-%d",&dob.dd,&dob.mm,&dob.yy);
    printf("Your DOB is : \n");
    printf("%d/%d/%d\n",dob.dd,dob.mm,dob.yy);
    printf("%d-%s-%d",dob.dd,month[dob.mm-1],dob.yy);
    return 0;

}