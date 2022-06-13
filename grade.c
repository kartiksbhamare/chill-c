#include<stdio.h>
int main()
{
 int math , chemestry , physics ;
 float total ;

 printf("enter math marks\n ");
 scanf("%d ", &math);
 printf("enter chemestry marks\n ");
 scanf("%d ", &chemestry );
printf("enter physics marks\n ");
 scanf("%d ",& physics );
  
  total = (math + physics+ chemestry)/3 ;
  if( (total<40) || physics<30 || chemestry<30 || math<30 )printf("you are fail and your total perncentage is %f"   ,total);

else printf("you are pass and total marks are %f" ,total );
    return 0;
}

