#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 30
typedef struct{
    char name[NAME_LENGTH];
    int score;
} Student;

void BubbleSort(int n, Student arr[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].score < arr[j+1].score || (arr[j].score == arr[j+1].score && strcmp(arr[j].name, arr[j+1].name) > 0)) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Student ss[50];

    for(int i = 0; i < n; i++) {
        scanf("%s %d", ss[i].name, &ss[i].score);
    }
    BubbleSort(n, ss);
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", ss[i].name, ss[i].score);
    }

    return 0;
}
