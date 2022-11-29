#include<stdio.h>

int main()
{
    int again;
    int s_boost = 5, p_boost = 5, a_boost = 5;
    int money = 100, time = 15, price = 30, spd_cost = 50, taste_cost = 100;
    int boost_state[3] = {0};
    int check[5] = {0};
    int earn_record[5] = {0};
    int hotdog_record[5] = {0};

    printf("Welcome, young boss!\n");

    do{
    int earn_this_round = 0;
    int action[4] = {0};

    //intro
    {
    printf("Chop chop, It's dawn.\n");
    printf("You have %d dollars.\n", money);
    printf("You need %d minutes to make a hotdog.\n", time);
    printf("The price of a hotdog is $%d.\n", price);
    }

    //booster
    printf("You have %d speed booster(s), %d price booster(s), %d area booster(s).\n", s_boost, p_boost, a_boost);
    int temp = 0;
    while(temp != 4)
    {
        while(1)
        {
            printf("Open/Close boosters: \n");
            printf("\t[1] Speed booster (now ");
            boost_state[0] ? printf("open)\n") : printf("close)\n");
            printf("\t[2] Price booster (now ");
            boost_state[1] ? printf("open)\n") : printf("close)\n");
            printf("\t[3] Area  booster (now ");
            boost_state[2] ? printf("open)\n") : printf("close)\n");
            printf("\t[4] Finish\n");
            printf("Enter the number(s): ");
            scanf("%d", &temp);
            if(temp < 1 || temp > 4) printf("Invalid input!!!!\n");
            else break;
        }
        if(boost_state[temp-1]) boost_state[temp-1] = 0;
        else boost_state[temp-1] = 1;
    }
    if(s_boost == 0) boost_state[0] = 0;
    if(p_boost == 0) boost_state[1] = 0;
    if(a_boost == 0) boost_state[2] = 0;

    //body text intro
    {
    printf("Actions you can take for each area:\n");
    printf("\t[1] Sell the hotdogs\n");
    printf("\t[2] Improve your cooking speed\n");
    printf("\t    (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", spd_cost, spd_cost*2, spd_cost*4, spd_cost*8);
    printf("\t[3] Improve your hotdog flavor\n");
    printf("\t    (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", taste_cost, taste_cost*2, taste_cost*4, taste_cost*8);
    }
    printf("Enter the number(s): ");
    scanf("%d%d%d%d", &action[0], &action[1], &action[2], &action[3]);
    for(int i = 0; i < 4; ++i)
    {
        while(1)
        {
            if(action[i] < 1 || action[i] > 3) printf("Invalid input!!!!\n");
            else break;
            printf("Actions you can take at Area %d: \n", i+1);
            printf("\t[1] Sell the hotdogs\n");
            printf("\t[2] Improve your cooking speed\n");
            printf("\t[3] Improve your hotdog flavor\n");
            printf("Enter the number(s): ");
            scanf("%d", &action[i]);
        }
    }

    //body
    int area = 0;
    while(area < 4)
    {
        int earn_here = 180 / time * price;
        if(boost_state[0] == 1) earn_here *= 2;
        if(boost_state[1] == 1) earn_here *= 2;
        switch(action[area])
        {
            case 1:
                money += earn_here;
                earn_this_round += earn_here;
                earn_record[area] = earn_here;
                hotdog_record[area] = 180 / time;
                if(boost_state[0] == 1) hotdog_record[area] *= 2;
                check[area] = 1;
                area++;
                break;
            case 2:
                if(money < spd_cost)
                {
                    money += earn_here;
                    earn_this_round += earn_here;
                    check[area] = 2;
                    area++;
                    break;
                }
                else if(time == 1)
                {
                    money += earn_here;
                    earn_this_round += earn_here;
                    check[area] = 3;
                    area++;
                    break;
                }
                else
                {
                    money -= spd_cost;
                    time--;
                    spd_cost *= 2;
                    check[area] = 4;
                    area++;
                    break;
                }
            case 3:
                if(money < taste_cost)
                {
                    money += earn_here;
                    earn_this_round += earn_here;
                    check[area] = 5;
                    area++;
                    break;
                }
                else
                {
                    money -= taste_cost;
                    price += 10;
                    taste_cost *= 2;
                    check[area] = 6;
                    area++;
                    break;
                }
        }
    }
    //area booster
    int earn_here = 180 / time * price;
    if(boost_state[0] == 1)
    {
        earn_here *= 2;
        --s_boost;
    }
    if(boost_state[1] == 1)
    {
        earn_here *= 2;
        --p_boost;
    }
    if(boost_state[2])
    {
        money += earn_here;
        earn_this_round += earn_here;
        earn_record[4] = earn_here;
        hotdog_record[4] = 180 / time;
        check[4] = 1;
    }
    printf("Well done, you earn $%d today.\n", earn_this_round);

    //check action when done
    int end, watch;
    if(boost_state[2]) end = 6;
    else end = 5;
    do
    {
        while(1)
        {
            printf("Which result of the area you want to check?\n");
            printf("\t[1] Area 1\n\t[2] Area 2\n\t[3] Area 3\n\t[4] Area 4\n");
            (end-5) ? printf("\t[5] Area 5\n\t[6] Done\n") : printf("\t[5] Done\n");
            printf("Enter the number(s): ");
            scanf("%d", &watch);
            if(watch < 1 || watch > end) printf("Invalid input!!!!\n");
            else break;
        }
        if(watch == end) break;
        switch(check[watch-1])
        {
            case 1:
                printf("You make %d hotdogs here!\n", hotdog_record[watch-1]);
                printf("You earn $%d!\n", earn_record[watch-1]);
                break;
            case 2:
                printf("Can't you tell how poor you are?\n");
                printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                break;
            case 3:
                printf("Do you want to travel through time?\n GO WORK!!\n");
                break;
            case 4:
                printf("You glimpse the secret of wind.\n");
                printf("Your hands can move faster now.\n");
                break;
            case 5:
                printf("Can't you tell how poor you are?\n");
                printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                break;
            case 6:
                printf("You feel the soul of the ingredients.\n");
                printf("Your hotdogs are more appetizing now.\n");
                break;
        }        
    }while(1);

    //end
    while(1)
    {
        printf("Do you want to continue or exit?\n");  
        printf("\t[1] Continue\n");
        printf("\t[2] Exit\n");
        printf("Enter the number(s): ");
        scanf("%d", &again);
        if(again < 1 || again > 2) printf("Invalid input!!!!\n");
        else break;
    }
    }while(again != 2);
    printf("We will miss you. Bye!\n");

    return 0;
}