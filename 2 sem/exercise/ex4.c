#include <stdio.h>
#include <string.h>

void create_data(), input_data(), watch_data();
int criminal_cnt = 0;

struct history{
    char crime[20];
    int year;
    int penalty;
};

struct criminal{
    char name[15];
    struct history crime_his[10];
    int crime_cnt;
};
struct criminal bad_ppl[10];

int main(){

    int o;
    while(1){
        printf("Enter a command: ");
        scanf("%d", &o);
        if(o == 0) break;
        void (*cmd[3])() = {create_data, input_data, watch_data};
        cmd[o-1]();
    }

    return 0;
}

void create_data(){
    printf("Enter a criminal's name: ");
    scanf("%s", bad_ppl[criminal_cnt].name);
    bad_ppl[criminal_cnt].crime_cnt = 0;
    printf("Created new criminal data (number %d).\n", criminal_cnt);
    criminal_cnt++;
}

void input_data(){
    int a;
    printf("Enter a number of the criminal: ");
    scanf("%d", &a);
    bad_ppl[a].crime_cnt++;
    printf("Enter crime: ");
    scanf(" %s", bad_ppl[a].crime_his[bad_ppl[a].crime_cnt-1].crime);
    printf("Enter date: ");
    scanf(" %d", &(bad_ppl[a].crime_his[bad_ppl[a].crime_cnt-1].year));
    printf("Enter penalty: ");
    scanf(" %d", &(bad_ppl[a].crime_his[bad_ppl[a].crime_cnt-1].penalty));
}

void watch_data(){
    int a;
    printf("Enter a number of the criminal: ");
    scanf("%d", &a);
    printf("Name: %s\n", bad_ppl[a].name);
    printf("====================\n");
    for(int i = 0; i < bad_ppl[a].crime_cnt; i++){
        printf("Year: %d, Crime: %s, Penalty: %d months\n"
            , bad_ppl[a].crime_his[i].year, bad_ppl[a].crime_his[i].crime, bad_ppl[a].crime_his[i].penalty);
    }
    printf("====================\n");
}