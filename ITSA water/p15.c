#include <stdio.h>

int arr[26], cnt;

int main(){

    int c;
    while(scanf("%c", &c) != EOF){
        if(c == ' '){
            cnt++;
            continue;
        }
        if(c > 'z'){
            arr[c - 'A']++;
        }
        else{
            arr[c - 'a']++;
        }
    }
    cnt++;

    printf("%d", cnt);
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0) printf("%c : %d\n", i, arr[i]);
    }

    return 0;
}