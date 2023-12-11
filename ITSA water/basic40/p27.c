#include <stdio.h>
#include <string.h>

int main(){
    char ref[5];
    scanf("%s", ref);
    while(1){
        int a = 0, b = 0;
        char tmp[5], zero[] = {'0', '0', '0', '0', '\0'};
        scanf("%s", tmp);
        if(strcmp(tmp, zero) == 0) break;
        for(int i = 0; i < 4; i++){
            if(ref[i] == tmp[i]) a++;
        }
        for(int i = 0; i < 4; i++){
            if(ref[i] != tmp[i]){
                for(int j = 0; j < 4; j++){
                    if(ref[i] == tmp[j]){
                        b++;
                        tmp[j] = 'A';
                        break;
                    }
                }
            }
        }
        printf("%dA%dB\n", a, b);
    }

    return 0;
}