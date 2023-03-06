#include<stdio.h>
#include<ctype.h>

void insert(int array[], int pos, int value), updation(int array[], int pos, int value), traversing(int array[]), deletion(int array[], int d);
int check(int input);

int main()
{
    int num_action;
    printf("num of actions: ");
    scanf("%d", &num_action);
    char action_arr[num_action];
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < num_action; ++i)
    {
        char t;
        do
        {
            t = getchar();
        }while(isspace(t));
        action_arr[i] = t;
    }

    for(int i = 0; i < num_action; ++i)
    {
        if(action_arr[i] != 'i' && action_arr[i] != 'u' && action_arr[i] != 't' && action_arr[i] != 'd')
        {
            printf("INVALID ACTION\n");
            continue;
        }
        int pos, value;
        switch(action_arr[i])
        {
            case 'i':
                insert(numbers, pos, value);
                break;
            case 'u':
                updation(numbers, pos, value);
                break;
            case 't':
                traversing(numbers);
                break;
            case 'd':
                deletion(numbers, pos);
        }
    }

    return 0;
}

void insert(int array[], int pos, int value)
{
    printf("position to insert: ");
    scanf("%d", &pos);
    if(check(pos)) return;
    printf("enter the value to insert: ");
    scanf("%d", &value);
    for(int i = 9; i > 0; --i)
    {
        if(i == pos) break;
        array[i] = array[i-1];
    }
    array[pos] = value;
    traversing(array);
}

void updation(int array[], int pos, int value)
{
    printf("position to update: ");
    scanf("%d", &pos);
    if(check(pos)) return;
    printf("enter the value to update: ");
    scanf("%d", &value);
    array[pos] = value;
    traversing(array);
}

void traversing(int array[])
{
    for(int i = 0; i < 10; ++i) printf("%d ", array[i]);
    printf("\n");
}

void deletion(int array[], int d)
{
    int pos;
    printf("position to delete: ");
    scanf("%d", &pos);
    if(check(pos)) return;
    array[pos] = 0;
    traversing(array);
}

int check(int input)
{
    if(input < 0 || input > 9)
    {
        printf("INVALID POSITION\n");
        return 1;
    }
    else return 0;
}