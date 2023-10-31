#include <stdio.h>

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
    for(int i = 0; i < n; i++){
        if(curr_path[i] == -1 && end_path[i] != -1){
            curr_path[i] = end_path[i];
        }
    }

    // count rounds
    for(int i = 0; i < n; i++){
        if(curr_path[i] != end_path[i] && end_path[i] != -1) round_cnt++;
    }
    printf("%d\n", round_cnt + 3);

    // print initial and first step
    for(int i = 0; i < n; i++) printf("%d ", start_path[i]);
    printf("\n");
    for(int i = 0; i < n; i++) printf("%d ", curr_path[i]);
    printf("\n");

    int tmp = n - 1;
    while(tmp != -1){
        if(curr_path[tmp] != end_path[tmp]){
            curr_path[tmp] = end_path[tmp];
            for(int i = 0; i < n; i++) printf("%d ", curr_path[i]);
            printf("\n");
        }
        tmp = inversed_path[tmp];
    }
    for(int i = 0; i < n; i++) printf("%d ", end_path[i]);
    printf("\n");

    return 0;
}