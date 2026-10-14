#include<stdio.h>
int main() {
float expense;
float smalltotal=0,mediumtotal=0,largetotal=0;
float total=0,average;
int smallcount=0,mediumcount=0,largecount=0;
int totalcount=0;
while(1)
{
printf("enter the expense(0 to stop):");
scanf("%f",&expense);
if(expense==0)
{
break;
}
else if(expense<0)
{
printf("invalid expense\n");
continue;
}
else
{
totalcount++;
total = total+expense;
if(expense < 100)
{
smallcount++;
smallcount = smalltotal+expense;
printf("category:small\n");
}
else if(expense<500)
{
mediumcount++;
mediumcount = mediumtotal+expense;
printf("category:medium\n");
}
else
{
largecount++;
largecount = largetotal+expense;
printf("category:large\n");
}
}
}
printf("the totalexpense :  %d\n",totalcount);
printf("the sum of totalexpense : %.2f\n",total);
printf("the smallcount : %d\n",smallcount);
printf("the sum of smallexpense : %.2f\n",smalltotal);
printf("the mediumcount : %d\n",mediumcount);
printf("sum of mediumcount : %.2f\n",mediumtotal);
printf("the largecount : %d\n",largecount);
printf("the sum of largecount : %.2f\n",largetotal);  
if(totalcount>0)
{
average = total / totalcount;
printf("average of valid expense = Rs %.2f\n",average);
}
else {
printf("invalid  \n");
}
return 0;
}
