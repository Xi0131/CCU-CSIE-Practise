#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_LENGTH 100

typedef struct {
    /* determine the structure by yourself. e.g, container of data, index... */
    int *ptr;
    int len;
} darray;

void initialize(darray *d);
void push_back(darray *d, int value);
int pop_back(darray *d);
int erase(darray *d, int position);
void insert(darray *d, int position, int value);
void clear(darray *d);
int sum(darray *d);
int length(darray *d);

void initialize(darray *d) {
    d->ptr = NULL;
    d->len = 0;
}

void push_back(darray* d, int value) {
    d->len++;
    d->ptr = realloc(d->ptr, (sizeof(int))*(d->len));
    (d->ptr)[(d->len) - 1] = value;
}

int pop_back(darray* d) {
    int temp = (d->ptr)[(d->len) - 1];
    d->len--;
    d->ptr = realloc(d->ptr, (sizeof(int))*(d->len));
    return temp;
}

int erase(darray *d, int position) {
    // return 1, if successfully erase the element.
    // return 0, if fail erase the element.
    if(position < 0 || position > (d->len - 1)){
        return 0;
    }
    else{
        for(int i = position; i < (d->len - 1); i++){
            (d->ptr)[i] = (d->ptr)[i + 1];
        }
        d->len--;
        d->ptr = realloc(d->ptr, (sizeof(int))*(d->len));
        return 1;
    }
}

void insert(darray *d, int position, int value) {
    d->len++;
    d->ptr = realloc(d->ptr, (sizeof(int))*(d->len));
    for(int i = (d->len) - 1; i > position; i--){
        (d->ptr)[i] = (d->ptr)[i - 1];
    }
    (d->ptr)[position] = value;
}

void clear(darray *d) {
    free(d->ptr);
    d->len = 0;
}

int sum(darray *d) {
    int ans = 0;
    for(int i = 0; i < d->len; i++){
        ans += (d->ptr)[i];
    }
    return ans;
}

int length(darray *d) {
    return d->len;
}

//YOU CAN'T MODIFY THE main() FUNCTION!!!
int main() {
    darray d;
    initialize(&d);
    int operation, param1, param2;
    while(scanf("%d", &operation)) {
        switch (operation)
        {
        case 1: //push_back
            scanf("%d", &param1);
            push_back(&d, param1);
            break;
        case 2: //pop_back
            printf("popped: %d\n", pop_back(&d));
            break;
        case 3: //erase
            scanf("%d", &param1);
            if(erase(&d, param1))
                printf("erase OK\n");
            else
                printf("erase not OK\n");
            break;
        case 4: //insert
            scanf(" %d %d ", &param1, &param2);
            insert(&d, param1, param2);
            break;
        case 5:
            clear(&d);
            break;
        case 6:
            printf("sum: %d\n", sum(&d));
            break;
        case 7:
            printf("length: %d\n", length(&d));
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}