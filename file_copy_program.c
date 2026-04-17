#include<stdio.h>

void main() {
    FILE *f1,*f2;
    f1 = fopen("hello.txt","r");
    f2 = fopen("bye.txt","w");
    char ch;

    while(ch != EOF) {
        ch = fgetc(f1);
         fputc(ch,f2);
    }
    fclose(f1);
    fclose(f2);
    printf("Data Copied Successfully");
}