#include<stdio.h>
#include<math.h>

int two_wines(int f), juice(int f), CO2(int f), shake(int f), base(int f);
void glass(int f);
void show_flavour(int input);

int main()
{
    int flavour = 0;
    printf("Let's make our first cocktail!\n");
    flavour = base(flavour);
    flavour = two_wines(flavour);
    flavour = two_wines(flavour);
    flavour = shake(flavour);
    flavour = juice(flavour);
    flavour = CO2(flavour);
    glass(flavour);
    printf("Let's make our second cocktail!\n");
    flavour = 0;
    flavour = base(flavour);
    flavour = two_wines(flavour);
    flavour = shake(flavour);
    flavour = juice(flavour);
    flavour = shake(flavour);
    flavour = CO2(flavour);
    flavour = two_wines(flavour);
    flavour = CO2(flavour);
    flavour = juice(flavour);
    flavour = shake(flavour);
    flavour = two_wines(flavour);
    flavour = shake(flavour);
    flavour = two_wines(flavour);
    flavour = juice(flavour);
    flavour = CO2(flavour);
    //Halfway here, huff and puff…
    flavour = shake(flavour);
    flavour = CO2(flavour);
    flavour = two_wines(flavour);
    flavour = shake(flavour);
    flavour = juice(flavour);
    flavour = juice(flavour);
    flavour = two_wines(flavour);
    flavour = two_wines(flavour);
    flavour = CO2(flavour);
    flavour = shake(flavour);
    flavour = two_wines(flavour);
    flavour = shake(flavour);
    flavour = two_wines(flavour);
    flavour = shake(flavour);
    glass(flavour);

    return 0;
}

void show_flavour(int input)
{
    printf("The flavor level increased %d!\n", input);
}

int base(int f)
{
    int base;
    printf("Let's select the base wine!\n");
    printf("Please Enter flavor level of the base wine: ");
    scanf("%d", &base);
    printf("The flavor level is %d!\n", base);
    return f += base;
}

int two_wines(int f)
{
    int w1, w2;
    printf("Now add two kinds of wines.\n");
    printf("Please Enter two types representing each wine: ");
    scanf("%d %d", &w1, &w2);
    int t;
    if(w2 > w1)
    {
        t = w1;
        w1 = w2;
        w2 = t;
    }
    while(w2 != 0)
    {
        t = w2;
        w2 = w1 % w2;
        w1 = t;
    }
    show_flavour(w1);
    return f += w1;
}

int juice(int f)
{
    int j;
    printf("Now add some juice.\n");
    printf("Please Enter flavor level of the juice: ");
    scanf("%d", &j);
    show_flavour(j);
    return f += j;
}

int CO2(int f)
{
    int c;
    printf("Now add some CO2.\n");
    printf("The current flavor level is %d.\n", f);
    printf("Please Enter power of CO2: ");
    scanf("%d", &c);
    if(c <= (f/2)) c *= 2;
    else if((f/2) < c && c <= f) c*= 3;
    show_flavour(c);
    return f += c;
}

int shake(int f)
{
    int pow, increamemt = 0;
    printf("Now shake.\n");
    do
    {
        printf("Please enter the power of a shake(0 to stop): ");
        scanf("%d", &pow);
        increamemt += pow;
    }while(pow != 0);
    show_flavour(increamemt);
    return f += increamemt;
}

void glass(int f)
{
    int t;
    printf("Finally, select a wine glass to pull your cocktail in.\n");
    printf("Please enter the number of wine glass(1 to 5): ");
    scanf("%d", &t);
    switch(t)
    {
        case 1:
            f += 10;
            printf("The price increased %d!\n", 10);
            break;
        case 2:
            f += 15;
            printf("The price increased %d!\n", 15);
            break;
        case 3:
            f += 17;
            printf("The price increased %d!\n", 17);
            break;
        case 4:
            f += 23;
            printf("The price increased %d!\n", 23);
            break;
        case 5:
            f += 40;
            printf("The price increased %d!\n", 40);
            break;
    }
    printf("Well done! The Price of this cocktail is %d!\n", f);
    return;
}