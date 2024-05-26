#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct card{
    char *suit;
    int number;
    struct card *next;
    struct card *prior;
};

char *input(){
    char a;
    char *name;
    name = malloc(100 * sizeof(char));
    int i = 0;
    while(1){
        if(scanf("%c", &a) == EOF) break;
        // scanf("%c", &a);
        // printf("hi %d\n", (int)a);
        if((a <= 'Z' && a >= 'A') || (a >= 'a' && a <= 'z') || a == '_'){
            name[i] = a;
            i++;
        }
        else{
            break;
        }  
    }
    name[i] = '\0';
    return name;
}

struct card *original(struct card *first, int num){
    struct card *temp = NULL;
    temp = malloc(sizeof(struct card));
    for(int i = 0; i < num; i++){
        struct card *new_node;
        new_node = malloc(sizeof(struct card));
        new_node->next = NULL;
        new_node->prior = NULL;
        new_node->suit = input();
        scanf("%d ", &new_node->number);
        
        if(i == 0){
            first = new_node;
            temp = first;
        }
        else{
            temp->next = new_node;
            new_node->prior = temp;
            temp = temp->next;
        }
    }
    return first;
}

struct card *find_end(struct card *first){
    for(struct card *p = first; p != NULL; p = p->next){
        if(p->next == NULL){
            return p;
        }
    }
    return first;
}

void see(struct card *first){
    for(struct card *p = first; p != NULL; p = p->next){
        printf("%s %d\n", p->suit, p->number);
    }
    return;
}

void see_r(struct card *end){
    for(struct card *p = end; p != NULL; p = p->prior){
        printf("%s %d\n", p->suit, p->number);
    }
    return;
}

void check(struct card *first){
    int compare_number;
    char *compare_name;
    compare_name = malloc(100 * sizeof(char));
    scanf("%s", compare_name);
    scanf(" %d", &compare_number);
    for(struct card *p = first; p != NULL; p = p->next){
        if(strcmp(p->suit, compare_name) == 0 && p->number == compare_number){
            printf("Checked!\n");
            return;
        }
    }
    printf("Nope!\n");
    return;
}

struct card *draw(struct card *first){
    struct card *new_node;
    new_node = malloc(sizeof(struct card));
    new_node->next = NULL;
    new_node->prior = NULL;
    new_node->suit = input();
    scanf("%d ", &new_node->number);
    //getchar();//去調換行
    first->prior = new_node;
    new_node->next = first;
    return new_node;
}

struct card *swap(struct card *first){
    char *name1, *name2, *temp_name;
    int num1, num2, temp_num;
    struct card *position1, *position2;
    position1 = malloc(sizeof(struct card));
    position2 = malloc(sizeof(struct card));
    name1 = input();
    scanf("%d ", &num1);
    //getchar();
    name2 = input();
    scanf("%d ", &num2);
    //getchar();
    for(struct card *p = first; p != NULL; p = p->next){
        if(strcmp(p->suit, name1) == 0 && p->number == num1){
            position1 = p;
        }
        if(strcmp(p->suit, name2) == 0 && p->number == num2){
            position2 = p;
        }
    }
    temp_name = position1->suit;
    temp_num = position1->number;
    position1->suit = position2->suit;
    position1->number = position2->number;
    position2->suit = temp_name;
    position2->number = temp_num; 
    return first;
}

struct card *play(struct card *first){
    char *name;
    int num, check_play = 0;
    name = input();
    scanf(" %d", &num);
    for(struct card *p = first; p != NULL; p = p->next){ 
        if(strcmp(p->suit, name) == 0 && p->number == num){
            check_play = 1;
            printf("Play %s %d!\n", p->suit, p->number);
            if(p->prior == NULL){
                first = p->next;
                first->prior = NULL;
            }
            else if(p->next == NULL){
                p->prior->next = NULL;
            }
            else{
                p->prior->next = p->next;
                p->next->prior = p->prior;
            }
            free(p->suit);
            free(p);
            free(name);
            return first;
        }
    }
    if(check_play == 0){
        printf("Play %s %d. I Bluffed!\n", name, num);
    }
    return first;
}

int main(){
    int num, operation;
    char *type;
    int count = 0;
    char *see_name, *see_r_name, *check_name, *draw_name, *swap_name, *play_name;
    see_name = "see";
    see_r_name = "see_r";
    check_name = "check";
    draw_name = "draw";
    swap_name = "swap";
    play_name = "play";
    scanf("%d ", &num);
    struct card *first;
    struct card *end;
    first = malloc(sizeof(struct card));
    end = malloc(sizeof(struct card));
    first->next = NULL;
    first->prior = NULL;
    end->next = NULL;
    end->prior = NULL;
    
    first = original(first, num);
    //see(first);
    
    scanf("%d ", &operation);
    for(int i = 0; i < operation; i++){
        count++;
        type = input();
        if(strcmp(type, see_name) == 0){
            see(first);
        }
        else if(strcmp(type, see_r_name) == 0){
            end = find_end(first);
            see_r(end);
        }
        else if(strcmp(type, check_name) == 0){
            check(first);
            i--;
        }
        else if(strcmp(type, play_name) == 0){
            first = play(first);
            i--;
        }
        else if(strcmp(type, draw_name) == 0){
            first = draw(first);
        }
        else if(strcmp(type, swap_name) == 0){
            first = swap(first);
        }
        free(type);
    }

    struct card *current = first;
    while (current != NULL) {
        struct card *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}