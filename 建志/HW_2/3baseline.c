#include <stdio.h>
#define debug printf("debug: %d\n", __LINE__)

int main(){

    int n, start_path[100001], end_path[100001], curr_path[100001], inversed_path[100001] = {0}, round_cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &start_path[i]);
        curr_path[i] = start_path[i];
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &end_path[i]);
        if(end_path[i] != -1) inversed_path[end_path[i]] = i;
    }
    inversed_path[0] = -1;

    // connect those who not connected
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(curr_path[i] == -1 && end_path[i] != -1){
            curr_path[i] = end_path[i];
            flag = 1;
        }
    }

    // count rounds
    int deduct = 0;
    for(int i = 0; i < n; i++){
        if(curr_path[i] != end_path[i] && end_path[i] != -1) round_cnt++;
    }
    if(flag){
        // debug;
        for(int i = 0; i < n; i++){
            if(curr_path[i] != start_path[i] && start_path[inversed_path[i]] != -1 && end_path[i] != -1){
                debug;
                curr_path[inversed_path[i]] = end_path[inversed_path[i]];    
                deduct++;
            }
        }
        printf("%d\n", round_cnt + 3 - deduct + 1);
    }
    else printf("%d\n", round_cnt + 1);
    // printf("%d\n", round_cnt + 3);

    // print initial and first step
    for(int i = 0; i < n; i++) printf("%d ", start_path[i]);
    printf("\n");
    if(flag){
        for(int i = 0; i < n; i++){
            if(start_path[i] == -1 && end_path[i] != -1){
                printf("%d ", end_path[i]);
            }
            else printf("%d ", start_path[i]);
        }
        printf("\n");
        for(int i = 0; i < n; i++) printf("%d ", curr_path[i]);
        printf("\n");
    }

    // back trace
    int tmp = n - 1;
    while(tmp != -1){
        // if not equal, modify path and print
        if(curr_path[tmp] != end_path[tmp]){
            curr_path[tmp] = end_path[tmp];
            for(int i = 0; i < n; i++) printf("%d ", curr_path[i]);
            printf("\n");
        }
        tmp = inversed_path[tmp];
    }
    if(flag){
        for(int i = 0; i < n; i++) printf("%d ", end_path[i]);
        printf("\n");
    }

    return 0;
}