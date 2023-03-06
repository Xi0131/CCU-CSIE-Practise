#include<stdio.h>
#include<stdbool.h>

int main()
{
    char t;
    int words = 1, v = 0;
    bool stop_counting = 0;
    char vovel[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    while((t = getchar()) != EOF)
    {
        if((t == ' ') && stop_counting)
        {
            continue;
        }
        else if(t == ' ')
        {
            words++;
            stop_counting = 1;
            continue;
        }

        stop_counting = 0;
        for(int i = 0; i < 10; i++)
        {
            if(t == vovel[i])
            {
                v++;
                break;
            }
        }
    }

    printf("%d %d", v, words);

    return 0;
}