#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void map_sys(int *money, int *booster_record,int bst_record_size), show_map(const char *map, int size);

int main()
{
    int money = 100, cook_time = 15, price = 30, spd_cost = 50, taste_cost = 100;       // initialize money, cook time, price of hotdog, cost to upgrade cooking speed and flavour

    int s_boost = 0, p_boost = 0, a_boost = 0;
    int boost_state[3] = {0};
    int booster_record[rand() % 10 + 6];

    int earn_record[5] = {0};
    int hotdog_record[5] = {0};
    int check[5] = {0};

    int again, choice;
    int choice_cost = 500, n = 3;
    int matrix_fulled = 0;
    int choice_count = 0;
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

    printf("Welcome, young boss!\n");
    printf("You have %d slots for booster.\n", sizeof(booster_record)/sizeof(booster_record[0]));

    next_round:
    do{
        int earn_this_round = 0;
        int action[4] = {0};

        //intro
        {
        printf("Chop chop, It's dawn.\n");
        printf("You have %d dollars.\n", money);
        printf("You need %d minutes to make a hotdog.\n", cook_time);
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
            int earn_here = 180 / cook_time * price;
            if(boost_state[0] == 1) earn_here *= 2;
            if(boost_state[1] == 1) earn_here *= 2;
            switch(action[area])
            {
                case 1:
                    money += earn_here;
                    earn_this_round += earn_here;
                    earn_record[area] = earn_here;
                    hotdog_record[area] = 180 / cook_time;
                    if(boost_state[0] == 1) hotdog_record[area] *= 2;
                    check[area] = 1;
                    area++;
                    break;
                case 2:
                    if(money < spd_cost)
                    {
                        money += earn_here;
                        earn_this_round += earn_here;
                        earn_record[area] = earn_here;
                        hotdog_record[area] = 180 / cook_time;
                        if(boost_state[0] == 1) hotdog_record[area] *= 2;
                        check[area] = 2;
                        area++;
                        break;
                    }
                    else if(cook_time == 1)
                    {
                        money += earn_here;
                        earn_this_round += earn_here;
                        earn_record[area] = earn_here;
                        hotdog_record[area] = 180 / cook_time;
                        if(boost_state[0] == 1) hotdog_record[area] *= 2;
                        check[area] = 3;
                        area++;
                        break;
                    }
                    else
                    {
                        money -= spd_cost;
                        cook_time--;
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
                        earn_record[area] = earn_here;
                        hotdog_record[area] = 180 / cook_time;
                        if(boost_state[0] == 1) hotdog_record[area] *= 2;
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
        int earn_here = 180 / cook_time * price;
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
            hotdog_record[4] = 180 / cook_time;
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
                    printf("You make %d hotdogs here!\n", hotdog_record[watch-1]);
                    printf("You earn $%d!\n", earn_record[watch-1]);
                    break;
                case 3:
                    printf("Do you want to travel through time?\n GO WORK!!\n");
                    printf("You make %d hotdogs here!\n", hotdog_record[watch-1]);
                    printf("You earn $%d!\n", earn_record[watch-1]);
                    break;
                case 4:
                    printf("You glimpse the secret of wind.\n");
                    printf("Your hands can move faster now.\n");
                    break;
                case 5:
                    printf("Can't you tell how poor you are?\n");
                    printf("Go vending your hotdogs instead of thinking about self-improvement!\n");
                    printf("You make %d hotdogs here!\n", hotdog_record[watch-1]);
                    printf("You earn $%d!\n", earn_record[watch-1]);
                    break;
                case 6:
                    printf("You feel the soul of the ingredients.\n");
                    printf("Your hotdogs are more appetizing now.\n");
                    break;
            }
            printf("Welcome to the map system\n");
            map_sys(&money, booster_record, sizeof(booster_record)/sizeof(booster_record[0]));

        }while(1);

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
        while(1)
        {
            printf("You get one free choice.\n");
            ++choice_count;
            do
            {
                //check if fulled
                for(int i = 0; i < n; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        if(choosen[i][j] == 0)
                        {
                            matrix_fulled = 0;
                            break;
                        }
                        else matrix_fulled = 1;
                    }
                }
                if(matrix_fulled)
                {
                    choice_cost = 500;
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
                if(choice == 0) goto next_round;
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
                        goto next_round;
                        break;
                    }
                    else money -= choice_cost;
                }
                here:
                choosen[a][b] = -1;

                //find prize_type
                srand(time(NULL));
                int prize_type = rand() % 9 + 1;

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
                        if(a == n) a = 0;
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
                        if(b == n) b = 0;
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

    }while(1);
    printf("We will miss you. Bye!\n");
    
    return 0;
}

void map_sys(int *money, int *booster_record, int bst_record_size)
{
    printf("Welcome to map system.\n");
    int m_length = 8;
    int m_reward, b_reward, choice;                 // temp. variable for containing reward amount, booster type and user choice
    int r_P = 0, c_P = 0, r_M, c_M, r_B, c_B;       // record position of user, money and booster
    int m_got = 0, b_got = 0;                       // variable for checking if the reward is obtained
    char map[m_length][m_length];                   // create map
    srand(time(NULL));

    map[0][0] = 'P'; // assign P
    for(char *p = &map[0][0]; p <= &map[m_length][m_length]; p++) // fill map 
        *p = '.';
    map[0][0] = 'P';
    while(1) // assign M
    {
        int i = rand() % m_length;
        int j = rand() % m_length;
        if(map[i][j] != 'P')
        {
            map[i][j] = 'M';
            r_M = i;
            c_M = j;
            m_reward = (i + 1) * (j + 1) * 10;
            break;
        }
    }
    while(1) // assign B
    {
        int i = rand() % m_length;
        int j = rand() % m_length;
        if(map[i][j] != 'M' || map[i][j] != 'P')
        {
            map[i][j] = 'B';
            r_B = i;
            c_B = j;
            b_reward = rand() % 3 + 1;
            break;
        }
    }
    
    // body function
    while(1)
    {
        // point where user comes back when previous choice is out of boundary
        choose_again:
        // print map and ask user to choose
        while(1)
        {
            show_map(&map[0][0], m_length);
            printf("Please choose one of the following actions to move: \n");
            printf("(Each move cost $25)\n");
            printf("\t[1] Up\n\t[2] Down\n\t[3] Left\n\t[4] Right\n\t[5] Exit (Does not cost any)\n");
            printf("Enter the number: ");
            scanf("%d", &choice);
            if(choice < 1 || choice > 5)
            {
                printf("Invalid input!!!!\n");
                continue;
            }
            else break;
        }
        // exit when no money
        if(*money < 25)
        {
            printf("You have no enough money!!!\n");
            return;
        }

        // do action
        *money -= 25;
        switch(choice)
        {
            case 1:
                if(r_P - 1 < 0)
                {
                    printf("You are going outside of the map!!!\n");
                    goto choose_again;
                }
                // swap
                map[r_P][c_P] = '.';
                r_P--;
                map[r_P][c_P] = 'P';
                break;
            case 2:
                if(r_P + 1 > m_length - 1)
                {
                    printf("You are going outside of the map!!!\n");
                    goto choose_again;
                }
                // swap
                map[r_P][c_P] = '.';
                r_P++;
                map[r_P][c_P] = 'P';
                break;
            case 3:
                if(c_P - 1 < 0)
                {
                    printf("You are going outside of the map!!!\n");
                    goto choose_again;
                }
                // swap
                map[r_P][c_P] = '.';
                c_P--;
                map[r_P][c_P] = 'P';
                break;
            case 4:
                if(c_P - 1 > m_length - 1)
                {
                    printf("You are going outside of the map!!!\n");
                    goto choose_again;
                }
                // swap
                map[r_P][c_P] = '.';
                c_P++;
                map[r_P][c_P] = 'P';
                break;
            case 5:
                return;
        }

        // get reward
        if(r_P == r_M && c_P == c_M)
        {
            *money += m_reward;
            m_got = 1;
            printf("You gain $%d!\n", m_reward);
        }
        else if(r_P == r_B && c_P == c_B)
        {
            int pos;
            for(int i = 0; i < bst_record_size; i++)
            {
                // if array is not full
                if(booster_record[i] == 0)
                {
                    pos = i;
                    break;
                }

                // if array is fulled
                for(int j = 0; j < bst_record_size - 2; j++)
                {
                    booster_record[j] = booster_record[j + 1];
                }
                pos = bst_record_size - 1;
            }
            booster_record[pos] = b_reward;
            b_got = 1;

            // show booster
            switch(b_reward)
            {
                case 1:
                    printf("You get a speed booster!\n");
                    break;
                case 2:
                    printf("You get a price booster!\n");
                    break;
                case 3:
                    printf("You get an area booster!\n");
                    break;
            }
        }
    
        // exit when no reward ramain
        if(m_got == 1 && b_got == 1)
        {
            printf("The rewards is empty!\n");
            break;
        }
    }

    return;
}

void show_map(const char *map, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%c ", *(map + i * size + j));
        }
        printf("\n");
    }
}