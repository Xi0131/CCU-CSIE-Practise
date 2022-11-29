#include<stdio.h>

int main()
{
    int choice_count = 0, money = 100, price = 30;
    int s_boost = 0, p_boost = 0, a_boost = 0;
    int again, choice;
    int choice_cost = 500, n = 3;
    int matrix_fulled = 0;
    int poison[100][100];
    int choosen[100][100];
    //fill poison, choosen
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            poison[i][j-1] = (i * n) + j;
            choosen[i][j-1] = 0;
        }
    }

    while(1)
    {
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
        ++choice_count;
        do
        {
            //check if fulled
            int flag = 0;
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(choosen[i][j] == 0)
                    {
                        matrix_fulled = 0;
                        flag = 0;
                        break;
                    }
                    else matrix_fulled = 1;
                }
            }
            if(matrix_fulled)
            {
                n += 2;
                //fill matrix
                for(int i = 0; i < n; ++i)
                {
                    for(int j = 1; j <= n; ++j)
                    {
                        poison[i][j-1] = (i * n) + j;
                        choosen[i][j-1] = 0;
                    }
                }
            }
            //DRAW MATRIX
            int z = n*n, size_max_n = 0;
            int row = 0;
            //calculate digits of n*n
            while(z != 0)
            {
                z /= 10;
                size_max_n++;
            }
            int width = size_max_n + 2;
            //print matrix
            for(int i = 0; i < n; ++i)
            {
                //print sides
                for(int j = 0; j < n; ++j)
                {
                    printf("+");
                    for(int k = 0; k < width; ++k) printf("-");
                }printf("+\n");
                //print numbers
                for(int j = 0; j < n; ++j)
                {
                    printf("| ");
                    if(poison[row][j] < pow(10, (size_max_n-1)))
                    {
                        int digit = 0, t = poison[row][j];
                        while(t != 0)
                        {
                            t /= 10;
                            ++digit;
                        }
                        for(int k = 0; k < (size_max_n-digit); ++k) printf(" ");
                    }
                    if(choosen[row][j] == -1)
                    {
                        if(poison[row][j] >= pow(10, (size_max_n-1)))
                        {
                            int digit = 0, t = 1;
                            while(t != 0)
                            {
                                t /= 10;
                                ++digit;
                            }
                            for(int k = 0; k < (size_max_n-digit); ++k) printf(" ");
                        }
                        printf("x ");
                    }
                    else printf("%d ", poison[row][j]);
                }printf("|\n");
                ++row;
            }
            //print last row
            for(int i = 0; i < n; ++i)
            {
                printf("+");
                for(int j = 0; j < width; ++j) printf("-");
            }printf("+\n");

            //DO LOTTERY
            //input and check invalid
            printf("You can choose\n");
            if(choice_count != 0) printf("\t[number on cell] to open (- $0)\n");
            else printf("\t[number on cell] to open (- $%d)\n", choice_cost);
            printf("\t[0] to continue the game\n");
            printf("Enter the number(s): ");
            scanf("%d", &choice);
            if(choice < 0 || choice > n*n)
            {
                printf("Invalid input!!!!\n");
                continue;
            }
            if(choice == 0) break;
            //find position
            int a = ((choice-1) / n);
            int b = ((choice-1) % n);
            if(choosen[a][b] == -1)
            {
                printf("Invalid input!!!!\n");
                continue;
            }
            else if(choice_count == 0)
            {
                if(money < choice_cost)
                {
                    printf("You have no money!\n");
                    break;
                }
                else money -= choice_cost;
            }
            here:
            choosen[a][b] = -1;

            //find prize_type
            //make char
            int remainder[4] = {0};
            int t = poison[a][b], pos = 3, x, reverse = 0;
            while (t != 0) {
                x = t % 10;
                reverse = reverse * 10 + x;
                t /= 10;
            }
            while (reverse != 0)
            {
                remainder[pos] = reverse % 10;
                reverse /= 10;
                --pos;
            }
            //make dec
            int dec = 0;
            dec += remainder[0] * pow(16, 3);
            dec += remainder[1] * pow(16, 2);
            dec += remainder[2] * pow(16, 1);
            dec += remainder[3] * 1;
            int prize_type = (dec % 9) + 1;

            //mechanism
            switch(prize_type)
            {
                case 1:
                    money += 100 * price;
                    printf("Fortune, fortune! You get $%d!\n", 100 * price);
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    break;
                case 2:
                    printf("You get an extra choice!\n");
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    ++choice_count;
                    break;
                case 3:
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    a -= 1;
                    if(a == -1) a = n-1;
                    if(choosen[a][b] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", poison[a][b]);
                        ++choice_count;
                        goto here;
                    }
                case 4:
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    a += 1;
                    if(a == n+1) a = 0;
                    if(choosen[a][b] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", poison[a][b]);
                        ++choice_count;
                        goto here;
                    }
                case 5:
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    b -= 1;
                    if(b == -1) b = n-1;
                    if(choosen[a][b] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", poison[a][b]);
                        ++choice_count;
                        goto here;
                    }
                case 6:
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    b += 1;
                    if(b == n+1) b = 0;
                    if(choosen[a][b] == -1)
                    {
                        printf("Bad Luck :(\n");
                        break;
                    }
                    else
                    {
                        printf("Another open on %d!\n", poison[a][b]);
                        ++choice_count;
                        goto here;
                    }
                case 7:
                    s_boost++;
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    printf("You get a booster!!\n");
                    break;
                case 8:
                    p_boost++;
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    printf("You get a booster!!\n");
                    break;
                case 9:
                    a_boost++;
                    if(choice_count == 0) choice_cost += 500;
                    else --choice_count;
                    printf("You get a booster!!\n");
                    break;
            };
        }while(1);
    }
    printf("Speed booster: %d\n", s_boost);
    printf("Price booster: %d\n", p_boost);
    printf("Area booster: %d\n", a_boost);
    printf("Money: %d\n", money);
    printf("Free choice: %d\n", choice_count);
    printf("We will miss you. Bye!");

    return 0;    
}