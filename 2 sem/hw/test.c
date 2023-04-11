#include <stdio.h>
#include <string.h>

int main(){

    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    for (int i = 0; i < sizeof(planets)/sizeof(planets[0]); i++)
	    if (planets[i][0] == 'M')
            printf("%s begins with M\n", planets[i]);
    printf("%d\n", sizeof(planets));
    printf("%d\n", sizeof(planets[0]));
    printf("%d\n", sizeof(planets)/sizeof(planets[0]));
    printf("%d\n", sizeof(int*));
    
    return 0;
}