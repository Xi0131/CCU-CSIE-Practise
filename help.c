#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void generateWords(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }

    for (int i = start; i <= end; i++) {
        // Swap the current character with the first character
        swap(&str[start], &str[i]);
        printf("%d %d %d %s\n", start + 1, start, i, str);

        // Recursively generate words for the remaining characters
        generateWords(str, start + 1, end);

        // Undo the swap to backtrack
        swap(&str[start], &str[i]);
    }
}

int main() {
    char input[11]; // maximum length of input is 10 characters
    scanf("%s", input);

    int n = strlen(input); //length of %s

    // Sort the characters in ascending order
    for (int i = 0; i < n - 1; i++) {  //last one is \0.
        for (int j = 0; j < n - i - 1; j++) {
            if (input[j] > input[j + 1]) {
                swap(&input[j], &input[j + 1]);
            }
        }
    }

    // Generate and print all possible words
    generateWords(input, 0, n - 1);

    return 0;
}

