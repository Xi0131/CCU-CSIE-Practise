#include <stdio.h>

int main(){
    int x, head[3], n;
    int money = 0, record[7] = {0};
    scanf("%d%d%d%d%d", &x, &head[0], &head[1], &head[2], &n);
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        if(tmp == x){
            money += 2000000;
            record[0]++;
            continue;
        }
        else{
            int flag = 0;
            for(int i = 8; i > 2; i--){
                for(int j = 0; j < 3; j++){
                    if(tmp % (10 * i) == head[j] % (10 * i)){
                        switch(i)
                        {
                        case 8:
                            money += 200000;
                            record[1]++;
                            flag = 1;
                            break;
                        case 7:
                            money += 40000;
                            record[2]++;
                            flag = 1;
                            break;
                        case 6:
                            money += 10000;
                            record[3]++;
                            flag = 1;
                            break;
                        case 5:
                            money += 4000;
                            record[4]++;
                            flag = 1;
                            break;
                        case 4:
                            money += 1000;
                            record[5]++;
                            flag = 1;
                            break;
                        case 3:
                            money += 200;
                            record[6]++;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
        }
    }

    for(int i = 0; i < 7; i++) printf("%d ", record[i]);
    printf("\n%d\n", money);

    return 0;
}