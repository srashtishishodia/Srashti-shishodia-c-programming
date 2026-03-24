#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int i;

    printf("Enter full name: ");
    fgets(name, sizeof(name), stdin);

    int len = strlen(name);
    if(name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("%c. ", name[0]);

    for(i = 0; name[i] != '\0'; i++) {
        if(name[i] == ' ') {
            if(name[i+1] != '\0') {
                int j;
                int spaceCount = 0;
                for(j = i+1; name[j] != '\0'; j++) {
                    if(name[j] == ' ') {
                        spaceCount++;
                    }
                }
                if(spaceCount > 0) {
                    printf("%c. ", name[i+1]); 
                } else {
                    printf("%s", &name[i+1]);
                    break;
                }
            }
        }
    }

    printf("\n");
    return 0;
}