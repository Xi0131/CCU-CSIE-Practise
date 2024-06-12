#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stringLen(char *s){
    int len = 0;
    while(*s){
        len++;
        s++;
    }
    return len;
}

int stringCompare(char *s1, char *s2){
    char *ptr = s1;
    char *qtr = s2;
    while(*ptr == *qtr && *ptr && *qtr){
        ptr++;
        qtr++;
    }
    return *ptr - *qtr;
}

char *stringFind(char *s1, char *s2){
    char *ptr = s1;
    char *qtr = s2;
    int len1 = stringLen(ptr);
    int len2 = stringLen(qtr); 
    //fprintf(stderr, "here::%s %d\nthere::%s %d\n", ptr, len1, qtr, len2);
    for (int i = 0; i <= len1 - len2; i++){
        if (ptr[i] == qtr[0]){
            int find = 1;
            for (int j = 0; j < len2; j++){
                if (ptr[i + j] != qtr[j]){
                    find = 0;
                    break;
                }
            }
            if (find == 1) return ptr + i;
        }
    }

    return NULL;
}

void stringCopy(char *s1, char *s2){
    int len = stringLen(s2);
    for (int i = 0; i < len; i++){
        s1[i] = s2[i];
    }
}

struct member{
    char name[100];
    int warning;
};

int main(){
    int messegeCnt = 1;
    int memberCnt = 1;
    char name[100];
    char bannedWord[200];
    char messege[4096];
    struct member members[1000];
    scanf("%d %s\n", &messegeCnt, bannedWord);

    for (int i = 0; i < messegeCnt; i++){
        
        int obligate = 0;
        int findmember = 0;

        fgets(messege, 4095, stdin);
        char *split = stringFind(messege, ":");
        char *namepos, *messegepos;
        
        *split = '\0';
        namepos = messege;
        messegepos = split + 1;
        int messegeLen = stringLen(messegepos);
        if (messegepos[messegeLen - 1] == '\n') messegepos[messegeLen - 1] = '\0';
//fprintf(stderr, "case: %d %s: %s\n", i, messege, messegepos);

        if (stringFind(messegepos, bannedWord)) obligate = 1;
        
        for (int j = 1; j < memberCnt; j++){
            if (stringCompare(members[j].name, namepos) == 0){
                members[j].warning += obligate;
                findmember = j;
                //fprintf(stderr, "name: %d %s", j, members[j].name);
                break;
            }
        }
        if (findmember == 0){
            stringCopy(members[memberCnt].name, namepos);
            members[memberCnt].warning = obligate;
            findmember = memberCnt;
            memberCnt++;
            //fprintf(stderr, "f name: %d %s", memberCnt, members[memberCnt-1].name);
        }

        if (members[findmember].warning == 3){
            members[findmember].warning = 4;
            printf("%s is banned.\n", namepos);
            //fprintf(stderr, "%d", i);
        }
//if (obligate) fprintf(stderr, " obligate: %s %d %d", members[findmember].name, findmember, members[findmember].warning);

        if (members[findmember].warning < 3 && obligate == 0){
            printf("%s:%s\n", namepos, messegepos);
        }
        //fprintf(stderr, "\n");
    }
    fprintf(stderr, "%d\n", memberCnt);
    return 0;
}