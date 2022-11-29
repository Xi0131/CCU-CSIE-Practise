#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validity(int input, int L, int U)
{
    if(input == NULL)
    {
        printf("Enter the number(s): ");
        scanf("%d", &input);
    }
    if(input < L || input > U)
    {
        printf("Invalid input!!!!");
        return input = 0;
    }
    return input;
}

int main()
{
    int money = 100, time = 15, price = 30, spd_cost = 50, taste_cost = 100, free_choice = 0;
    int earn_here;
    int wrong_input = 0;
    int booster[4] = {0};//speed, price, area
    int boost_state[4] = {0}, action[4] = {0}, check[6] = {0}, earn_record[6][2];//hotdog sold & earn_here

    printf("Welcome, young boss!\n");

    while(1)
    {
        //intro
        int earn_this_round = 0, area = 1;
        printf("Chop chop, It's dawn.\n");
        printf("You have %d dollars.\n", money);
        printf("You need %d minutes to make a hotdog.\n", time);
        printf("The price of a hotdog is $%d.\n", price);
        
        //booster
        printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", booster[0], booster[1], booster[2]);
        int temp;
        while(temp != 4)
        {
            printf("Open/Close boosters: \n");
            printf("\t[1] Speed booster (now ");
            boost_state[0] ? printf("open)\n") : printf("close)\n");
            printf("\t[2] Price booster (now ");
            boost_state[1] ? printf("open)\n") : printf("close)\n");
            printf("\t[3] Area booster (now ");
            boost_state[2] ? printf("open)\n") : printf("close)\n");
            printf("\t[4] Finish\n");
            temp = validity(temp, 1, 4);
            if(!temp)
            {
                temp = NULL;
                continue;
            }
            boost_state[temp-1] ? boost_state[temp-1] = 0 : boost_state[temp-1] = 1;
        }
        //close invalid booster
        for(int i = 0; i < 3; ++i) if(boost[i] == 0) boost_state[i] = 0;

        //body text intro
        printf("Actions you can take for each area:\n");
        printf("\t[1] Sell the hotdogs");
        printf("\t[2] Improve your cooking speed\n");
        printf("\t\t(- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", spd_cost, spd_cost*2, spd_cost*4, spd_cost*8);
        printf("\t[3] Improve your hotdog flavor\n");
        printf("\t\t(- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", taste_cost, taste_cost*2, taste_cost*4, taste_cost*8);
        printf("Enter the number(s): ");
        scanf("%d%d%d%d", &action[0], &action[1], &action[2], &action[3]);
        //body
        while(area <= 4){
            action[area-1] = validity(action[area-1], 1, 4);
            if(!action[area-1])
            {
                printf("Actions you can take at Area %d: \n");
                printf("\t[1] Sell the hotdogs\n");
                printf("\t[2] Improve your cooking speed\n");
                printf("\t[3] Improve your hotdog flavor\n");
                action[area-1] = NULL;
                continue;
            }

            earn_here = 180 / time * price;
            earn_record[area-1][0] = 180 /time;
            earn_record[area-1][1] = earn_here;
            switch(action[area-1])
            {
                case 1:
                    money += earn_here;
                    earn_this_round += earn_here;
                    area++;
                    check[area-1] = 1;
                    break;
                case 2:
                    if(money < spd_cost)
                    {
                        money += earn_here;
                        earn_this_round += earn_here;
                        area++;
                        check[area-1] = 2;
                        break;
                    }
                    else if(time == 1)
                    {
                        money += earn_here;
                        earn_this_round += earn_here;
                        area++;
                        check[area-1] = 3;
                        break;
                    }
                    else
                    {
                        money -= spd_cost;
                        time--;
                        spd_cost *= 2;
                        area++;
                        check[area-1] = 4;
                        break;
                    }
                case 3:
                    if(money < taste_cost)
                    {
                        money += earn_here;
                        earn_this_round += earn_here;
                        area++;
                        check[area-1] = 5;
                        break;
                    }
                    else
                    {
                        money -= taste_cost;
                        price += 10;
                        taste_cost *= 2;
                        area++;
                        check[area-1] = 6;
                        break;
                    }
                default:
                    printf("Actions you can take at Area %d: \n", area);
                    printf("\t[1] Sell the hotdogs\n");
                    printf("\t[2] Improve your cooking speed\n");
                    printf("\t[3] Improve your hotdog flavor\n");
            }
            printf("Well done, you earn $%d today.", earn_this_round);
        }
        //area booster
        if(boost_state[2])
        {
            money += earn_here;
            earn_this_round += earn_here;
            check[4] = 1;
        }

        //check action when done
        int end;
        boost_state[2] ? end = 6 : end = 5;
        do
        {
            printf("Which result of the area you want to check?\n");
            printf("\t[1] Area 1\n\t[2] Area 2\n\t[3] Area 3\n\t\n\t[4] Area 4\n");
            (end-5) ? printf("\t[5] Area 5\n\t[6] Done\n") : printf("\t[5] Done\n");
            temp = validity(temp, 1, end);
            //show results
            if(temp != end)
            {
                switch(check[temp-1])
                {
                    case 1:
                        printf("You make %d hotdogs here!", earn_record[temp-1][0]);
                        printf("You earn $%d!", earn_record[temp-1][1]);
                    case 2:
                        printf("Can't you tell how poor you are?\n");
                        printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    case 3:
                        printf("Do you want to travel through time?\n GO WORK!!\n");
                    case 4:
                        printf("You glimpse the secret of wind.\n");
                        printf("Your hands can move faster now.\n");
                    case 5:
                        printf("Can't you tell how poor you are?\n");
                        printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    case 6:
                        printf("You feel the soul of the ingredients.\n");
                        printf("Your hotdogs are more appetizing now.\n");
                }
            }
        }while(temp != end);

        int again;
        printf("Do you want to continue or exit?");
        again = validity(again, 1, 2);
        if(again == 2) break;
        return 0;
    }
}