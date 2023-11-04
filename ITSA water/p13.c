#include <stdio.h>

int n, s[14], h[14], d[14], c[14];

int main(){

    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        char t, space;
        int tmp;
        do{
            t = getchar();
            scanf("%d", &tmp);
            space = getchar();
            switch(t){
                case 'S':
                    s[tmp]++;
                    break;
                case 'H':
                    h[tmp]++;
                    break;
                case 'D':
                    d[tmp]++;
                    break;
                case 'C':
                    c[tmp]++;
                    break;
            }
        } while(space != '\n' || space != EOF);

        for(int j = 13; j >=0; j--){
            if(s[j] != 0){
                printf("S%d ", j);
                s[j] = 0;
            }
        }
        for(int j = 13; j >=0; j--){
            if(h[j] != 0){
                printf("H%d ", j);
                h[j] = 0;
            }
        }
        for(int j = 13; j >=0; j--){
            if(d[j] != 0){
                printf("D%d ", j);
                d[j] = 0;
            }
        }
        for(int j = 13; j >=0; j--){
            if(c[j] != 0){
                printf("C%d ", j);
                c[j] = 0;
            }
        }
        printf("\n");
    }

    return 0;
}