#include<stdio.h>
int main()
{
    int i ;
    for ( i = 0; i < 10000; i++)
    {
       printf("the value of i is %d\n",i);
     if (i == 2)
     {
        break;
     }
     
       
    }
    
    return 0;
}
