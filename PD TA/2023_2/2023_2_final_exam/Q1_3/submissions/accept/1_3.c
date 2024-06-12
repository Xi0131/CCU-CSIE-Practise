#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

struct Node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct Node* next;
};

struct Node* insert(struct Node* head, char* word) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = NULL;

    if (head == NULL || strcmp(word, head->word) < 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* prev = head;
        struct Node* current = head->next;
        while (current != NULL && strcmp(word, current->word) > 0) {
            prev = current;
            current = current->next;
        }
        prev->next = newNode;
        newNode->next = current;
    }
    return head;
}

struct Node* search(struct Node* head, char* word) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    char word[MAX_WORD_LENGTH];

    while (fgets(word, sizeof(word), stdin) != NULL) {
        word[strcspn(word, "\n")] = '\0';
        
        if (strcmp(word, "0") == 0) {
            break;
        }
        
        if (word[0] == '-' && head != NULL) {
            struct Node* foundNode = search(head, word + 1); 
            if (foundNode != NULL) {
                foundNode->count--;
            }
        } else {
            struct Node* foundNode = search(head, word);
            if (foundNode != NULL) {
                foundNode->count++;
            } else {
                head = insert(head, word);
            }
        }
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s %d\n", temp->word, temp->count);
        temp = temp->next;
    }


    freeList(head);

    return 0;
}