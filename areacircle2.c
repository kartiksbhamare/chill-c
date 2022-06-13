#include<stdio.h>
int main()
{
    int radius;

    float pi;
    printf("what is the radius of circle\n " );
    scanf("%d",&radius);
    printf("what is the value of pi\n " );
    scanf("%f", &pi);
    printf("the area of circle is %f ",radius*pi*radius);
    return 0;
}
