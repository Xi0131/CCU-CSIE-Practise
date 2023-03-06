#include<stdio.h>
#include<ctype.h>

int main()
{
    char s;
    int byte = 0, L_count = 0, U_count = 0, Digit_count = 0, White_count = 0, Line_count = 0;
    int Char_count = 0;
    int arr[26] = {0};//https://stackoverflow.com/questions/5636070/zero-an-array-in-c-code

    int CHECKER = 1;
    do
    {
        s = getchar();

        if(CHECKER)
        {
            if(s == EOF)break;
            else
            {
                ++Line_count;
                CHECKER = 0;
            }
        }
        else if(s == EOF) break;
        
        ++byte;
        if(s >= 'A' && s <= 'Z')
        {
            for(int i = 'A'; i <= 'Z'; i++)
            {
                if(s == i)
                {
                    ++Char_count;
                    ++arr[i-'A'];
                    ++U_count;
                    break;
                }
            }
            continue;
        }
        else if(s >= 'a' && s <= 'z')
        {
            for(int i = 'a'; i <= 'z'; i++)
            {
                if(s == i)
                {
                    ++Char_count;
                    ++arr[i-'a'];
                    ++L_count;
                    break;
                }
            }
        }

        if(s == '\n')
        {
            CHECKER = 1;
            ++White_count;
            continue;
        }
        else if(s >= '0' && s <= '9')
        {
            ++Digit_count;
            continue;
        }
        else if(isspace(s))
        {
            ++White_count;
            continue;
        }
    }while(1);

    printf("Bytes Count: %d\n", byte);
    printf("Lowercase Count: %d\n", L_count);
    printf("Uppercase Count: %d\n", U_count);
    printf("Digit Count: %d\n", Digit_count);
    printf("Whitespace Count: %d\n", White_count);
    printf("Line Count: %d\n", Line_count);

    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(Char_count == 0)++Char_count;
        float x = arr[i-'A']*1.0/Char_count;
        printf("%c/%c: %d, %3.3f\n", i, i+32, arr[i-'A'], x);
    }

    return 0;
}