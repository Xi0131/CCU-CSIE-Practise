#include<stdio.h>

int main()
{
    printf("Welcome, Adventurer!\n");

    int b, s, L;
    printf("Please enter blood, strength, level: ");
    scanf("%d %d %d", &b, &s, &L);

    int mon[4] = {L, (L%2) + 2, L > 3? L : 3, L*4};
    int dmg[4] = {1+L, 2+L, 3+L, 4+L};

    int choice;

    int re = 1;
    while(re == 1)
    {
        while(1)
        {
            printf("You have %d blood and %d strength.\n", b, s);
            printf("Please choose which monster (1 to 4) you want to fight: ");
            scanf("%d", &choice);

            if(choice > 4 || choice < 1)
            {
                printf("No such monster, please enter 1 to 4 to choose the monster.\n");
                break;
            }
            
            printf("You are fighting Monster %d!\n", choice);

            if(s > mon[choice-1])
            {
                printf("You Win!\n");
                s++;
                break;
            }
            else
            {
                printf("You Lose!\n");
                b -= dmg[choice-1];
                break;
            }
        }
        printf("Do you want to go on your adventure (1: Yes; 0: No) ?: ");
        scanf("%d", &re);
        if(b <= 0 && re == 1)
        {
            printf("You have %d blood and %d strength.\n", b, s);
            printf("You Dead. Bye!");
            break;
        }
        else if(re == 0 || re != 1)
        {
            printf("We will miss you. Bye!");
            break;
        }
    }

    return 0;
}