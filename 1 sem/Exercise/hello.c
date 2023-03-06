#include<stdio.h>
#include<math.h>

int main()
{
    double m, n;
    n = 80009.0;
    double t1 = 5 * n * n + 4;
    double t2 = 5 * pow(n, 2) - 4;
    double m1 = sqrt(t1);
    double m2 = sqrt(t2);
    printf("%e",t1);
    printf("%e",m2*m2);
    if(m1*m1 == t1)
    {
        printf("yes1");
    }
    else
    {
        printf("no1");
    }

    if(m2*m2 == t2)
    {
        printf("yes2");
    }
    else
    {
        printf("no2");
    }

    return 0;
}
