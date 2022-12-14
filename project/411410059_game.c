#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define watch(x) printf(#x" is %d\n", x)                                                // tool for debug

void map_sys(int *money, int *booster_record,int bst_record_size), show_map(const char *map, int size);
void booster_sys(int *boost_state, int s_boost, int p_boost, int a_boost);
void check_action(int boost_state_2, int *hotdog_record, int *earn_record, int *booster_record, int *money, int *check);
void del_booster(int *booster_record, int bst_record_size, int old_booster_type);
void add_booster(int *booster_record, int *bst_record_size, int new_booster);
void cal_booster(int *booster_record, int bst_record_size, int *s_boost, int *p_boost, int *a_boost);
void deductfree_or_addcost(int *free_choice, int *choice_cost);
void lottery(int *free_choice, int *lot_size, int *matrix_fulled, int *choice_cost, int *money, int *price, int **choosen, int **poison, int *booster_record, int *bst_record_size);
void earn_money(int *money, int *earn_this_round, int *earn_record, int *hotdog_record, int *boost_state, int earn_here, int area, int cook_time);
void rand_event_with_input(int *x);
void rick_is_rolling(), QR_code();
void continue_game(int *again);
void action_validation(int *action);

int main()
{
    srand(time(NULL));
    int money = 100, cook_time = 15, price = 30, spd_cost = 50, taste_cost = 100;       // initialize money, cook time, price of hotdog, cost to upgrade cooking speed and flavour

    int s_boost = 0, p_boost = 0, a_boost = 0;                                          // initialize numbers of each booster
    int boost_state[4] = {0};                                                           // initialize booster state for each round
    int booster_record[rand() % 11 + 5];                                                // create space for records booster
    int bst_record_size = (int) sizeof(booster_record)/sizeof(booster_record[0]);       // store the booster record size
    int earn_record[5] = {0};                                                           // record money earn if selling action occurs
    int hotdog_record[5] = {0};                                                         // record hotdog sold if selling action occurs
    int check[5] = {0};                                                                 // record actions at each area

    int again, choice;                                                                  // create variable for lottery
    int choice_cost = 500, lot_size = 3;                                                // cost of each choice, initial size of lottery
    int matrix_fulled = 0;                                                              // for checking if lottery is empty
    int free_choice = 0;                                                                // store free choice
    int **poison = malloc(100 * sizeof(int *));                                         // store number of lottery
    int **choosen = malloc(100 * (int) sizeof(int *));                                  // store state of each number in lottery
    for(int i = 0; i < 50; ++i)
    {
        poison[i] = malloc(100 * (int) sizeof(int *));
        choosen[i] = malloc(100 * (int) sizeof(int *));
    }
    
    // fill poison, booster_record
    for(int i = 0; i < lot_size; ++i)
    {
        for(int j = 1; j <= lot_size; ++j)
        {
            poison[i][j-1] = (i * lot_size) + j;
            choosen[i][j-1] = 0;
        }
    }
    for(int i = 0; i < bst_record_size; i++)
    {
        booster_record[i] = 0;
    }

    // greetings
    printf("Welcome, young boss!\n");
    printf("You have %d slots for booster.\n", bst_record_size);
    // booster_record[0] = 1;
    while(1)
    {
        int earn_this_round = 0;                                                        // record money earned in a day
        int action[4] = {0};                                                            // store action choosen for each area
        
        // calculate number of booster owned
        cal_booster(booster_record, bst_record_size, &s_boost, &p_boost, &a_boost);

        // start of new day
        printf("Chop chop, It's dawn.\n");
        printf("You have %d dollars.\n", money);
        printf("You need %d minutes to make a hotdog.\n", cook_time);
        printf("The price of a hotdog is $%d.\n", price);

        // booster
        booster_sys(boost_state, s_boost, p_boost, a_boost);

        // explanation of actions
        printf("Actions you can take for each area:\n");
        printf("\t[1] Sell the hotdogs\n");
        printf("\t[2] Improve your cooking speed\n");
        printf("\t    (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", spd_cost, spd_cost*2, spd_cost*4, spd_cost*8);
        printf("\t[3] Improve your hotdog flavor\n");
        printf("\t    (- $%d, - $%d, - $%d, - $%d for next four upgrades)\n", taste_cost, taste_cost*2, taste_cost*4, taste_cost*8);

        // action input
        printf("Enter the number(s): ");
        scanf("%d%d%d%d", &action[0], &action[1], &action[2], &action[3]);
        action_validation(action);

        // body
        int area = 0;
        while(area < 4)
        {
            int earn_here = 180 / cook_time * price;    // initialize total possible earn
            if(boost_state[0] == 1) earn_here *= 2;     // multiply money earn if spd boost is open
            if(boost_state[1] == 1) earn_here *= 2;     // multiply money earn if taste boost is open
            switch(action[area])
            {
                case 1:                     // earn money
                    earn_money(&money, &earn_this_round, earn_record, hotdog_record, boost_state, earn_here, area, cook_time);
                    check[area] = 1;
                    area++;
                    break;
                case 2:                     // upgrade cooking speed
                    if(money < spd_cost)    // case of no money
                    {
                        earn_money(&money, &earn_this_round, earn_record, hotdog_record, boost_state, earn_here, area, cook_time);
                        check[area] = 2;
                        area++;
                        break;
                    }
                    else if(cook_time == 1) // case of reached the time limit
                    {
                        earn_money(&money, &earn_this_round, earn_record, hotdog_record, boost_state, earn_here, area, cook_time);
                        check[area] = 3;
                        area++;
                        break;
                    }
                    else                    // case of successful upgrade
                    {
                        money -= spd_cost;
                        cook_time--;
                        spd_cost *= 2;
                        check[area] = 4;
                        area++;
                        break;
                    }
                case 3:                     // upgrade flavour
                    if(money < taste_cost)  // case of no money
                    {
                        earn_money(&money, &earn_this_round, earn_record, hotdog_record, boost_state, earn_here, area, cook_time);
                        check[area] = 5;
                        area++;
                        break;
                    }
                    else                    // case of successful upgrade
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
        
        // easter egg
        if((rand() % 10 + 1) == 10)
        {
        char name[1000] = {'\0'};
        int i = 0;
        printf("What is your teacher's name? \n");
        char c;
        while((c = getchar()) != '\n')
        {
            name[i] = c;
            ++i;
        }
        printf("Your teacher is %s.\n", name);
        printf("Please do not spell his/her name wrongly!\n");
        }

        // area booster
        int earn_here = 180 / cook_time * price;
        // delete and close used booster
        if(boost_state[0] == 1)
        {
            earn_here *= 2;
            boost_state[0] = 0;
            del_booster(booster_record, bst_record_size, 1);
        }
        if(boost_state[1] == 1)
        {
            earn_here *= 2;
            boost_state[1] = 0;
            del_booster(booster_record, bst_record_size, 2);
        }
        if(boost_state[2])
        {
            earn_money(&money, &earn_this_round, earn_record, hotdog_record, boost_state, earn_here, 4, cook_time);
            check[4] = 1;
            boost_state[2] = 0;
            del_booster(booster_record, bst_record_size, 3);
        }
        
        // end of day
        printf("Well done, you earn $%d today.\n", earn_this_round);

        // check action when done
        check_action(boost_state[2], hotdog_record, earn_record, booster_record, &money, check);

        // ask if continue
        continue_game(&again);
        if(again == 2) break;
        
        // loterry
        lottery(&free_choice, &lot_size, &matrix_fulled, &choice_cost, &money, &price, choosen, poison, booster_record, &bst_record_size);
    }
    printf("We will miss you. Bye!\n");

    // easter egg
    QR_code();

    system("411410059_thanks.txt");

    return 0;
}

void booster_sys(int *boost_state, int s_boost, int p_boost, int a_boost)
{
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
            rand_event_with_input(&temp);
            if(temp < 1 || temp > 4) printf("Invalid input!!!!\n");
            else break;
        }
        if(boost_state[temp-1]) boost_state[temp-1] = 0;
        else boost_state[temp-1] = 1;
    }
    if(s_boost == 0) boost_state[0] = 0;
    if(p_boost == 0) boost_state[1] = 0;
    if(a_boost == 0) boost_state[2] = 0;
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
        if(map[i][j] != 'M' && map[i][j] != 'P')
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
            rand_event_with_input(&choice);
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

void check_action(int boost_state_2, int *hotdog_record, int *earn_record, int *booster_record, int *money, int *check)
{
    int end, watch;
    if(boost_state_2) end = 6;
    else end = 5;
    while(1)
    {
        printf("Which result of the area you want to check?\n");
        printf("\t[1] Area 1\n\t[2] Area 2\n\t[3] Area 3\n\t[4] Area 4\n");
        (end-5) ? printf("\t[5] Area 5\n\t[6] Done\n") : printf("\t[5] Done\n");
        printf("Enter the number(s): ");
        rand_event_with_input(&watch);
        if(watch < 1 || watch > end) printf("Invalid input!!!!\n");
        else break;
    }
    if(watch == end) return;
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
    map_sys(money, booster_record, sizeof(booster_record)/sizeof(booster_record[0]));
    check_action(boost_state_2, hotdog_record, earn_record, booster_record, money, check);
}

void lottery(int *free_choice, int *lot_size, int *matrix_fulled, int *choice_cost, int *money, int *price, int **choosen, int **poison, int *booster_record, int *bst_record_size)
{
    int choice;
    printf("You get one free choice.\n");
    ++*free_choice;
    while(1)
    {
        // check if fulled
        for(int i = 0; i < *lot_size; ++i)
        {
            for(int j = 0; j < *lot_size; ++j)
            {
                if(choosen[i][j] == 0)
                {
                    *matrix_fulled = 0;
                    break;
                }
                else *matrix_fulled = 1;
            }
        }
        if(*matrix_fulled)
        {
            *choice_cost = 500;
            *lot_size += 2;
            //fill matrix
            for(int i = 0; i < *lot_size; ++i)
            {
                for(int j = 1; j <= *lot_size; ++j)
                {
                    poison[i][j-1] = (i * (*lot_size)) + j;
                    choosen[i][j-1] = 0;
                }
            }
        }
        // draw matrix
        int z = (*lot_size)*(*lot_size), size_max_n = 0;
        int row = 0;
        // calculate digits of lot_size*lot_size
        while(z != 0)
        {
            z /= 10;
            size_max_n++;
        }
        int width = size_max_n + 2;
        // print matrix
        for(int i = 0; i < *lot_size; ++i)
        {
            //print sides
            for(int j = 0; j < *lot_size; ++j)
            {
                printf("+");
                for(int k = 0; k < width; ++k) printf("-");
            }printf("+\n");
            //print numbers
            for(int j = 0; j < *lot_size; ++j)
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
                    for(int k = 0; k < (size_max_n - digit); ++k) printf(" ");
                }
                if(choosen[i][j] == -1)
                {
                    if(poison[row][j] >= pow(10, (size_max_n - 1)))
                    {
                        int digit = 0, t = 1;
                        while(t != 0)
                        {
                            t /= 10;
                            ++digit;
                        }
                        for(int k = 0; k < (size_max_n - digit); ++k) printf(" ");
                    }
                    printf("x ");
                }
                else printf("%d ", poison[row][j]);
            }printf("|\n");
            ++row;
        }
        // print last row
        for(int i = 0; i < *lot_size; ++i)
        {
            printf("+");
            for(int j = 0; j < width; ++j) printf("-");
        }printf("+\n");

        // DO LOTTERY
        // input and check invalid
        printf("You can choose\n");
        if(*free_choice != 0) printf("\t[number on cell] to open (- $0)\n");
        else printf("\t[number on cell] to open (- $%d)\n", *choice_cost);
        printf("\t[0] to continue the game\n");
        printf("Enter the number(s): ");
        rand_event_with_input(&choice);
        if(choice < 0 || choice > (*lot_size)*(*lot_size))      // check invalid if out of range
        {
            printf("Invalid input!!!!\n");
            continue;
        }
        else if(*free_choice == 0 && *money < *choice_cost)     // check if no money and no free choice
        {
            printf("You have no enough money!\n");
            break;
        }
        if(choice == 0) break;
        // find position
        int a = ((choice-1) / *lot_size);
        int b = ((choice-1) % *lot_size);
        if(choosen[a][b] == -1)                                 // check invalid if choosen
        {
            printf("Invalid input!!!!\n");
            continue;
        }
        else if(*free_choice > 0)
        {
            --*free_choice;
        }
        else
        {
            *money -= *choice_cost;
            *choice_cost += 500;
        }
        here:
        choosen[a][b] = -1;

        // find prize_type
        srand(time(NULL));
        int prize_type = rand() % 9 + 1;

        // prize mechanism
        switch(prize_type)
        {
            case 1:     // get money
                *money += 100 * (*price);
                printf("Fortune, fortune! You get $%d!\n", 100 * (*price));
                break;
            case 2:     // extra choice
                printf("You get an extra choice!\n");
                ++*free_choice;
                break;
            case 3:     // open up
                a -= 1;
                if(a == -1) a = *lot_size-1;
                if(choosen[a][b] == -1)
                {
                    printf("Bad Luck :(\n");
                    break;
                }
                else
                {
                    printf("Another open on %d!\n", poison[a][b]);
                    goto here;
                }
            case 4:     // open down
                a += 1;
                if(a == *lot_size) a = 0;
                if(choosen[a][b] == -1)
                {
                    printf("Bad Luck :(\n");
                    break;
                }
                else
                {
                    printf("Another open on %d!\n", poison[a][b]);
                    goto here;
                }
            case 5:     // open left
                b -= 1;
                if(b == -1) b = *lot_size-1;
                if(choosen[a][b] == -1)
                {
                    printf("Bad Luck :(\n");
                    break;
                }
                else
                {
                    printf("Another open on %d!\n", poison[a][b]);
                    goto here;
                }
            case 6:     // open right
                b += 1;
                if(b == *lot_size) b = 0;
                if(choosen[a][b] == -1)
                {
                    printf("Bad Luck :(\n");
                    break;
                }
                else
                {
                    printf("Another open on %d!\n", poison[a][b]);
                    ++*free_choice;
                    goto here;
                }
            case 7:     // get spd booster
                add_booster(booster_record, bst_record_size, 1);
                printf("You get a booster!!\n");
                break;
            case 8:     // get taste booster
                add_booster(booster_record, bst_record_size, 2);
                printf("You get a booster!!\n");
                break;
            case 9:     // get area booster
                add_booster(booster_record, bst_record_size, 3);
                printf("You get a booster!!\n");
                break;
        };
    }
}

void add_booster(int *booster_record, int *bst_record_size, int new_booster)
{
    int pos, fulled = 1;
    // if array is not full
    for(int i = 0; i < *bst_record_size; i++)
    {
        if(booster_record[i] == 0)
        {
            pos = i;
            fulled = 0;
            break;
        }
    }
    // if array is fulled
    if(fulled)
    {
        for(int j = 0; j < *bst_record_size - 2; j++)
        {
            booster_record[j] = booster_record[j + 1];
        }
        pos = *bst_record_size - 1;
    }
    booster_record[pos] = new_booster;
}

void del_booster(int *booster_record, int bst_record_size, int old_booster_type)
{
    for(int i = 0; i < bst_record_size; ++i)
    {
        if(booster_record[i] == old_booster_type)
        {
            for(int j = i; j < bst_record_size; ++j)
            {
                booster_record[j] = booster_record[j+1];
            }
            booster_record[bst_record_size-1] = 0;
        }
    }
}

void cal_booster(int *booster_record, int bst_record_size, int *s_boost, int *p_boost, int *a_boost)
{
    *s_boost = 0;
    *p_boost = 0;
    *a_boost = 0;
    for(int i = 0; i < bst_record_size; i++)
    {
        if(booster_record[i] == 1)
        {
            ++*s_boost;
        }
        else if(booster_record[i] == 2)
        {
            ++*p_boost;
        }
        else if(booster_record[i] == 3)
        {
            ++*a_boost;
        }
    }
}

void deductfree_or_addcost(int *free_choice, int *choice_cost)
{
    if(*free_choice == 0) *choice_cost += 500;
    else --*free_choice;
}

void earn_money(int *money, int *earn_this_round, int *earn_record, int *hotdog_record, int *boost_state, int earn_here, int area, int cook_time)
{
    *money += earn_here;
    *earn_this_round += earn_here;
    earn_record[area] = earn_here;
    hotdog_record[area] = 180 / cook_time;
    if(boost_state[0] == 1) hotdog_record[area] *= 2;
}

void rand_event_with_input(int *x)
{
    int y;
    scanf("%d", &y);
    *x = y;
    srand(time(NULL));
    if((rand() % 10 + 1) == 10)
    {
        rick_is_rolling();
        printf("You have been rick rolled!!!\n");
    }
}

void rick_is_rolling()
{
    // rick roll music
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

void continue_game(int *again)
{
    while(1)
    {
        printf("Do you want to continue or exit?\n");
        printf("\t[1] Continue\n");
        printf("\t[2] Exit\n");
        printf("Enter the number(s): ");
        rand_event_with_input(again);
        if(*again < 1 || *again > 2)
        {
            printf("Invalid input!!!!\n");
        }else break;
    }
}

void QR_code()
{
    printf("Please check out the following QR code\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@                  @@@     @@@@@@@@@@   @@             @@@                  @@\n");
    printf("@@@   @@@@@@@@@@@@&  @@@@@@@@@@@@@@@@  @@@@@@@@     @@@@@@@@  @@@@@@@@@@@@@   @@\n");
    printf("@@@   @@        @@&  @@@  @@@@@           @@@@@@@(  @@@  @@@  @@@        @@   @@\n");
    printf("@@@   @@        @@&  @@@     @@   @@@  @@@             @@@@@  @@@        @@   @@\n");
    printf("@@@   @@        @@&  @@@          @@@  @@@  @@@@@@@@   @@@@@  @@@        @@   @@\n");
    printf("@@@   @@@@@@@@@@@@&  @@@@@   @@@@@     @@@@@@@@          @@@  @@@@@@@@@@@@@   @@\n");
    printf("@@@                  @@@  @@@  @@@   @@   @@   @@(  @@@  @@@                  @@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@   @@   @@@@@@@@               @@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@          @@@@@&  @@@  @@@@@@@@@@@     @@@@@        @@   @@@@@        @@   @@\n");
    printf("@@@@@@@@   @@     .@@   @@   @@@@@@@@@@   @@   @@@@@     @@@        @@@@@@@   @@\n");
    printf("@@@             @@&  @@@  @@@@@@@@@@@  @@@@@   @@(  @@@  @@@        @@     @@@@@\n");
    printf("@@@@@@  @@@     @@@@@   @@@@@@@           @@   @@(  @@@             @@@@@@@   @@\n");
    printf("@@@@@@       @@@     @@@@@   @@   @@@            /@@   @@@@@@@@@@@@@     @@@@@@@\n");
    printf("@@@     @@@       .@@@@@  @@@     @@@@@   @@     /@@     @@@     @@@@@        @@\n");
    printf("@@@   @@   @@        @@@@@     @@@   @@   @@   @@@@@        @@      @@        @@\n");
    printf("@@@     @@@     @@@@@@@@  @@@@@@@@   @@        @@@@@@@@  @@@        @@@@@  @@@@@\n");
    printf("@@@   @@        @@&  @@@@@@@@     @@@@@@@@@@@@@@@(  @@@     @@@@@     @@@  @@@@@\n");
    printf("@@@@@@     @@   @@@@@        @@@@@   @@     @@@@@(  @@@     @@   @@@       @@@@@\n");
    printf("@@@   @@@@@  @@@@@&  @@@             @@@@@     @@@@@@@@@@@@@@@   @@@@@   @@@@@@@\n");
    printf("@@@@@@@@          .@@@@@@@@@@@@@@@   @@   @@     /@@        @@@@@@@@@@   @@@@@@@\n");
    printf("@@@@@@  @@@  @@@@@&                  @@     @@@                          @@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@       @@@   @@@@@@@@@@@@(  @@@  @@@@@@@@             @@\n");
    printf("@@@                  @@@@@                @@@@@@@@@@     @@@  @@@     @@@  @@@@@\n");
    printf("@@@   @@@@@@@@@@@@&  @@@@@   @@@@@@@@       @@@@@(  @@@  @@@@@@@@     @@@  @@@@@\n");
    printf("@@@   @@        @@&  @@@@@@@@  @@@   @@          /@@@@@             @@        @@\n");
    printf("@@@   @@        @@&  @@@  @@@@@      @@@@@     @@@@@        @@@@@     @@@@@   @@\n");
    printf("@@@   @@        @@&  @@@  @@@     @@@  @@@@@@@@@@@@@@@@@@   @@   @@@@@   @@   @@\n");
    printf("@@@   @@@@@@@@@@@@&  @@@  @@@@@   @@@@@   @@   @@(       @@@@@   @@@  @@@  @@@@@\n");
    printf("@@@                  @@@  @@@@@@@@@@@@@        @@@@@     @@@@@@@@@@@  @@@  @@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void action_validation(int *action)
{
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
            rand_event_with_input(&action[i]);
        }
    }
}