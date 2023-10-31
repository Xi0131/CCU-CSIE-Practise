#include <stdio.h>

int main(){

    int n, start_path[10001], end_path[10001], curr_path[10001], inversed_path[10001], round_cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &start_path[i]);
        curr_path[i] = start_path[i];
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &end_path[i]);
        inversed_path[end_path[i]] = i;
    }

    int flag = 0;
    for(int i = 0; i < n; i++){
        if(curr_path[i] == -1 && end_path[i] != -1){
            flag = 1;
            curr_path[i] = end_path[i];
        }
    }

    int tmp = n - 1;
    while(tmp != 0){
        if(start_path[tmp] != -1) round_cnt++;
        tmp = inversed_path[tmp];
    }
    if(flag == 1) printf("%d\n", round_cnt + 4);
    else printf("%d\n", round_cnt + 2);

    for(int i = 0; i < n; i++) printf("%d ", start_path[i]);
    printf("\n");

    if(flag == 1){
        for(int i = 0; i < n; i++) printf("%d ", curr_path[i]);
        printf("\n");
    }

    tmp = n - 1;
    while(1){
        if(curr_path[tmp] != end_path[tmp]){
            curr_path[tmp] = end_path[tmp];
            for(int i = 0; i < n; i++) printf("%d ", curr_path[i]);
            printf("\n");
        }
        if(tmp == 0) break;
        tmp = inversed_path[tmp];
    }
    tmp = n - 1;
    for(int i = 0; i < n; i++){
        if(end_path[i] == -1) curr_path[i] = -1;
    }
    if(flag == 1){
        for(int i = 0; i < n; i++) printf("%d ", end_path[i]);
        printf("\n");
    }

    return 0;
}