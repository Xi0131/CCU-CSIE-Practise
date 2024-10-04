#include <stdio.h>
#define SHORT_SIZE 16
// function to rotate the given unsigned short
// in the right direction
unsigned short rightRotate(unsigned short x, int d)
{
   /**
    * By doing x >> d, we move the first (left most) d bits
    * to the right most d bits, and at the same time we move
    * the right most d bits to the right side,
    * performing OR operation between the two gives use the
    * required result.
    * */
   return (x >> d) | (x << (SHORT_SIZE - d));
}
/* Driver program to test above functions */
int main()
{
   // Test case
   unsigned short n = 0;
   int d = 1;
   scanf("%hu", &n);
   scanf("%d", &d);
  
   //output
   printf("%hu\n", rightRotate(n, d));
   return 0;
}
// This code is contributed by ganesh227
