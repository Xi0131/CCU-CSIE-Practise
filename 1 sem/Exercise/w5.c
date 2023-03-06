#include<stdio.h>

int main()
{
    int money = 100, time = 15, price = 30, spd_cost = 50, taste_cost = 100;
    int earn_here, move;
    int wrong_input = 0;

    printf("Welcome, young boss!\n");

    int re = 1;
    while (re == 1)
    {
        int earn_this_round = 0, area = 1;
        printf("Chop chop, It's dawn.\n");

        while(area <= 4)
        {
            printf("You are at Area %d.\n", area);
            printf("You have %d dollars.\n", money);
            printf("You need %d minutes to make a hotdog.\n", time);
            printf("The price of a hotdog is $%d.\n", price);
            earn_here = 180 / time * price;

            //input(move, 1, 3);
            do
            {
                printf("Please choose which action you want to take: \n");
                printf("\t[1] Sell the hotdogs (+ $%d)\n", earn_here);
                printf("\t[2] Improve your cooking speed (- $%d / - 1 min for making a hotdog)\n", spd_cost);
                printf("\t[3] Improve your hotdog flavor (- $%d / + $10 for each hotdog)\n", taste_cost);
                printf("Enter the number: ");
                scanf("%d", &move);
            
                if(move < 1 || move > 3)
                {
                    wrong_input = 1;
                    printf("Invalid input!!!!\n");
                }
                else wrong_input = 0;
            
            }while(wrong_input == 1);

            switch(move)
            {
            case 1:
                money += earn_here;
                earn_this_round += earn_here;
                area++;
                printf("You make %d hotdogs here!\n", 180 / time);
                printf("You earn $%d!\n", earn_here);
                break;

            case 2:
                if(money < spd_cost)
                {
                    printf("Can't you tell how poor you are?\n");
                    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    printf("You make %d hotdogs here!\n", 180 / time);
                    printf("You earn $%d!\n", earn_here);
                    //func
                    money += earn_here;
                    earn_this_round += earn_here;
                    area++;
                    break;
                }
                else if(time == 1)
                {
                    printf("Do you want to travel through time? GO WORK!!\n");
                    printf("You make %d hotdogs here!\n", 180 / time);
                    printf("You earn $%d!\n", earn_here);
                    money += earn_here;
                    earn_this_round += earn_here;
                    area++;
                    break;
                }
                else
                {
                    money -= spd_cost;
                    time--;
                    spd_cost *= 2;
                    printf("You glimpse the secret of wind.\n");
                    printf("Your hands can move faster now.\n");
                    area++;
                    break;
                }

            case 3:
                if(money < taste_cost)
                {
                    printf("Can't you tell how poor you are?\n");
                    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    printf("You make %d hotdogs here!\n", 180 / time);
                    printf("You earn $%d!\n", earn_here);
                    money += earn_here;
                    earn_this_round += earn_here;
                    area++;
                    break;
                }
                else
                {
                    money -= taste_cost;
                    price += 10;
                    taste_cost *= 2;
                    printf("You feel the soul of the ingredients.\n");
                    printf("Your hotdogs are more appetizing now.\n");
                    area++;
                    break;
                }
            }
        }

        printf("Well done, you earn $%d today.\n", earn_this_round);
        
        do
        {
            printf("Do you want to continue or exit?\n");
            printf("\t[1] Continue\n");
            printf("\t[2] Exit\n");
            printf("Enter the number: ");
            scanf("%d", &re);

            if(re < 1 || re > 2)
            {
                wrong_input = 1;
                printf("Invalid input!!!!\n");
            }
            else wrong_input = 0;

        }while(wrong_input == 1);

        if(re == 2)
        {
            printf("We will miss you. Bye!");
            break;
        }
    }

    return 0;
}