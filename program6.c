#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countChar(char str[], char ch) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch) {
            count++;
        }
    }
    return count;
}

int countWords(char str[]) {
    int words = 0, inWord = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            if(inWord == 0) {
                words++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return words;
}

void printAlphabetFreq(char str[]) {
    for(char ch = 'A'; ch <= 'Z'; ch++) {
        int freq = countChar(str, ch) + countChar(str, tolower(ch));
        if(freq > 0) {
            printf("%c : %d\n", ch, freq);
        }
    }
}

int main() {
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    if(str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    printf("\nNumber of words: %d\n", countWords(str));

    printf("\nFrequency of each alphabet:\n");
    printAlphabetFreq(str);

    return 0;
}