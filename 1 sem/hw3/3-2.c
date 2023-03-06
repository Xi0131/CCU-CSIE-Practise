#include<stdio.h>
#include<ctype.h>

int main()
{
    int ans = 0;
    char t;
    char abc[] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U', 'D', 'G', 'B', 'C', 'M', 'P', 'F', 'H', 'V', 'W', 'Y', 'K', 'J', 'X', 'Q', 'Z'};
    int score[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 8, 8, 10, 10};
    
    while((scanf("%c", &t)) != EOF)
    {
        t = toupper(t);
        for(int i = 0; i < 26; i++)
        {
            if(t == abc[i])
            {
                ans += score[i];
                break;
            }
        }
    }

    printf("%d", ans);

    return 0;
}