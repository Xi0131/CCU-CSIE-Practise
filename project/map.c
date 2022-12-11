#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void map_sys(int *money, int *booster_record,int bst_record_size), show_map(const char *map, int size);

int main()
{
    int money = 1000000;
    int booster_record[10] = {0};
    map_sys(&money, booster_record, 10);

    return 0;
}

void map_sys(int *money, int *booster_record, int bst_record_size)
{
    printf("Welcome to map system.\n");
    int m_length = 8;
    int m_reward, b_reward, choice;                 // temp. variable for containing reward amount, booster type and user choice
    int r_P = 0, c_P = 0, r_M, c_M, r_B, c_B;       // record position of user, money and booster
    int m_got = 0, b_got = 0;                       // variable for checking if the reward is obtained
    char map[m_length][m_length];                   // create 
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
            m_reward = i * j * 10;
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