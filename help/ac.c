#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 1000
#define MAX_LENGTH 20

struct card {
    char suit[MAX_LENGTH];
    int number;
};

int main() {
    int Card_num;
    scanf("%d", &Card_num);
    struct card cards[MAX_CARDS];

    for (int i = 0; i < Card_num; i++) {
        scanf("%s", cards[i].suit);
        scanf("%d", &cards[i].number);
    }

    int Comment_num;
    scanf("%d", &Comment_num);

    for (int i = 0; i < Comment_num; i++) {
        char Comment[MAX_LENGTH];
        scanf("%s", Comment);

        if (strcmp(Comment, "see") == 0) {
            for (int j = 0; j < Card_num; j++) {
                if (cards[j].suit[0] != '\0') {
                    printf("%s %d\n", cards[j].suit, cards[j].number);
                }
            }
        } else if (strcmp(Comment, "see_r") == 0) {
            for (int j = Card_num - 1; j >= 0; j--) {
                if (cards[j].suit[0] != '\0') {
                    printf("%s %d\n", cards[j].suit, cards[j].number);
                }
            }
        } else if (strcmp(Comment, "check") == 0) {
            struct card check;
            int find = 0;
            scanf("%s", check.suit);
            scanf("%d", &check.number);
            for (int j = 0; j < Card_num; j++) {
                if ((strcmp(check.suit, cards[j].suit) == 0) && (check.number == cards[j].number)) {
                    printf("Checked!\n");
                    find = 1;
                    break;
                }
            }
            if (!find) {
                printf("Nope!\n");
            }
        } else if (strcmp(Comment, "play") == 0) {
            struct card check;
            int find = 0;
            scanf("%s", check.suit);
            scanf("%d", &check.number);
            for (int j = 0; j < Card_num; j++) {
                if ((strcmp(check.suit, cards[j].suit) == 0) && (check.number == cards[j].number)) {
                    printf("Play %s %d!\n", check.suit, check.number);
                    cards[j].suit[0] = '\0';  // Invalidate the card
                    cards[j].number = 0;
                    find = 1;
                    break;
                }
            }
            if (!find) {
                printf("Play %s %d.  I Bluffed!\n", check.suit, check.number);
            }
        } else if (strcmp(Comment, "draw") == 0) {
            struct card check;
            scanf("%s", check.suit);
            scanf("%d", &check.number);
            for (int j = Card_num - 1; j >= 0; j--) {
                cards[j + 1] = cards[j];
            }
            cards[0] = check;
            Card_num++;
        } else if (strcmp(Comment, "swap") == 0) {
            struct card check1, check2;
            int mark1 = -1, mark2 = -1;
            scanf("%s", check1.suit);
            scanf("%d", &check1.number);
            scanf("%s", check2.suit);
            scanf("%d", &check2.number);
            for (int j = 0; j < Card_num; j++) {
                if ((check1.number == cards[j].number) && (strcmp(check1.suit, cards[j].suit) == 0)) {
                    mark1 = j;
                }
                if ((check2.number == cards[j].number) && (strcmp(check2.suit, cards[j].suit) == 0)) {
                    mark2 = j;
                }
            }
            if (mark1 != -1 && mark2 != -1) {
                struct card temp;
                temp = cards[mark1];
                cards[mark1] = cards[mark2];
                cards[mark2] = temp;
            }
        }
    }
    return 0;
}