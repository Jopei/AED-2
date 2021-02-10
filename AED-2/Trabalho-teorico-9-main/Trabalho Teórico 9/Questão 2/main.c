#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int x =9;
    *p = x*5;
   printf("%d", *(p+1));
    return 0;
}
