#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int roll_no;
    char mobile_no[15];
    float CGPA;
    char DoB[15];
    char course[50];
    int year;
};
void readStudent(struct Student *s) {
    printf("\nEnter Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Roll No: ");
    scanf("%d", &s->roll_no);

    printf("Enter Mobile No: ");
    scanf("%s", s->mobile_no);

    printf("Enter CGPA: ");
    scanf("%f", &s->CGPA);

    printf("Enter Date of Birth: ");
    scanf("%s", s->DoB);

    printf("Enter Course: ");
    scanf(" %[^\n]", s->course);

    printf("Enter Year: ");
    scanf("%d", &s->year);
}
void displayStudent(struct Student s) {
    printf("\n Student Details \n");
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll_no);
    printf("Mobile No: %s\n", s.mobile_no);
    printf("CGPA: %.2f\n", s.CGPA);
    printf("DoB: %s\n", s.DoB);
    printf("Course: %s\n", s.course);
    printf("Year: %d\n", s.year);
}
void findTopper(struct Student s[], int n) {
    int i, topperIndex = 0;

    for(i = 1; i < n; i++) {
        if(s[i].CGPA > s[topperIndex].CGPA) {
            topperIndex = i;
        }
    }

    printf("\n Topper of the Class:\n");
    displayStudent(s[topperIndex]);
}
int main() {
    struct Student students[10];
    int i;

    for(i = 0; i < 10; i++) {
        printf("\nEnter details of Student %d:", i + 1);
        readStudent(&students[i]);
    }
    printf("\n All Students Data \n");
    for(i = 0; i < 10; i++) {
        displayStudent(students[i]);
    }
    findTopper(students, 10);

    return 0;
}
