#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int free_choice = 0, money = 100, price = 30;
    int s_boost = 0, p_boost = 0, a_boost = 0, lottery_size = 3;
    int again;
    
    while(1)
    {
        int choice_cost = 0, n = 3;
        //continue?
        while(1)
        {
            printf("Do you want to continue or exit?\n");
            printf("\t[1] Continue\n");
            printf("\t[2] Exit\n");
            printf("Enter the number(s): ");
            scanf("%d", &again);
            if(again < 1 || again > 2)
            {
                printf("Invalid input!!!!\n");
            }else break;
        }
        if(again == 2) break;

        //loterry
        printf("You get one free choice.\n");
        ++free_choice;
        int choice;
        do
        {
            //DRAW MATRIX
            int z = n, size_z = 0;
            while(z != 0)
            {
                z /= 10;
                size_z++;
            }
            int width = size_z + 2;
            int poison[n][n];
            int choosen[n][n];
            choosen[0][0] = 0;
            int row = 0;
            //fill matrix
            char number[4];
            for(int i = 0; i < n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    poison[i][j-1] = (i * n) + j;
                }
            }
            //print matrix
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    printf("+");
                    for(int k = 0; k < width; ++k) printf("-");
                }printf("+\n");
                for(int j = 0; j < n; ++j)
                {
                    printf("| ");
                    if(choosen[row][j] == -1)
                    {
                        printf("x ");
                    }
                    else
                    {
                        printf("%d ", poison[row][j]);
                    }
                }printf("|\n");
                ++row;
            }
            for(int j = 0; j < n; ++j)
            {
                printf("+");
                for(int k = 0; k < width; ++k) printf("-");
            }printf("+\n");

            //DO LOTTERY
            //input and check invalid
            printf("You can choose\n");
            printf("\t[number on cell] to open (- $%d)\n", choice_cost);
            printf("\t[0] to continue the game\n");
            printf("Enter the number(s): ");
            scanf("%d", &choice);
            if(choice < 0 || choice > n*n)
            {
                printf("Invalid input!!!!\n");
                continue;
            }
            if(choice == 0)break;

            ccccchoice:
            //find position
            int a = (choice / n) - 1;
            int b = (choice % n) - 1;
            //do smtg

            poison[a][b];
            choosen[a][b] = -1;
            printf("%d\n", poison[a][b]);
            //make char and reverse
            int remainder[4];
            int t = poison[a][b], reverse = 0, pos = 0;
            while (t != 0)
            {
              remainder[pos] = t % 10;
              t /= 10;
            }

            int dec;
            dec += remainder[0] * 1000;
            dec += remainder[1] * 100;
            dec += remainder[2] * 10;
            dec += remainder[3] * 1;

            int prize_type = (dec % 9) + 1;

            switch(prize_type)
            {
                case 1:
                    money += 100 * price;
                    printf("Fortune, fortune! You get $%d!\n", 100 * price);
                    break;
                case 2:
                    printf("You get an extra choice!\n");
                    break;
                case 3:
                    choice = poison[a-1][b];
                    if(choosen[a-1][b] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", choice);
                        break;
                    }
                case 4:
                    choice = poison[a+1][b];
                    if(choosen[a+1][b] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", choice);
                        goto ccccchoice;
                        break;
                    }
                case 5:
                    choice = poison[a][b-1];
                    if(choosen[a][b-1] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", choice);
                        goto ccccchoice;
                        break;
                    }
                case 6:
                    choice = poison[a][b+1];
                    if(choosen[a][b+1] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", choice);
                        goto ccccchoice;
                        break;
                    }
                case 7:
                    s_boost++;
                    printf("You get a booster!!\n");
                    break;
                case 8:
                    p_boost++;
                    printf("You get a booster!!\n");
                    break;
                case 9:
                    a_boost++;
                    printf("You get a booster!!\n");
                    break;
            };
            choice_cost += 500;

        }while(choice != 0);
    }
    printf("Speed booster: %d\n", s_boost);
    printf("Price booster: %d\n", p_boost);
    printf("Area booster: %d\n", a_boost);
    printf("Money: %d\n", money);
    printf("Free choice: %d\n", free_choice);
    printf("We will miss you. Bye!");

    return 0;
}