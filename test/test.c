#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void rand_event_with_input(int *x);
void rick_is_rolling();

int main()
{
    char name[1000] = {'\0'};
    int x;
    int i = 0;
    // rand_event_with_input(&x);
    printf("What is your teacher's name? \n");
    char c;
    while((c = getchar()) != '\n')
    {
        name[i] = c;
        ++i;
    }
    printf("%s\n", name);

    return 0;
}

void rand_event_with_input(int *x)
{
    int y;
    scanf("%d", &y);
    *x = y;
    printf("%d", *x);
    srand(time(NULL));
    if(1)
    {
        rick_is_rolling();
        printf("You have been rick rolled\n");
    }
}

void rick_is_rolling()
{
    Beep(784,   120);
    Beep(880,   120);
    Beep(1046,  120);
    Beep(880,   120);
    Beep(1318,  480);
    Beep(1318,  480);
    Beep(1175,  480);

    Beep(784,   120);
    Beep(880,   120);
    Beep(1046,  120);
    Beep(880,   120);
    Beep(1175,  480);
    Beep(1175,  480);
    Beep(1046,  480);
    Beep(988,   120);
    Beep(880,   360);

    Beep(784,   120);
    Beep(880,   120);
    Beep(1046,  120);
    Beep(880,   120);
    Beep(1046,  480);
    Beep(1175,  240);
    Beep(988,   480);
    Beep(880,   120);
    Beep(784,   360);

    Sleep(240);
    Beep(784,   240);
    Beep(1175,  480);
    Beep(1046,  480);
}