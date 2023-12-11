#include <stdio.h>

int main(){
    int n, t, m, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &t, &m, &k);
        int arr[k];
        for(int j = 0; j < k; j++) scanf("%d", &arr[j]);
        for(int a = 0; a < k; a++){
            for(int b = 0; b < k; b++){
                if(arr[a] < arr[b]){
                    printf("%d %d\n", arr[a], arr[b]);
                    int tmp = arr[b];
                    arr[b] = arr[a];
                    arr[a] = tmp;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < m; j++){
            ans += arr[j];
        }
        if(ans > t) printf("Impossible\n");
        else printf("%d\n", ans);
    }

    return 0;
}