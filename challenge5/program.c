#include<stdio.h>
#include<math.h>
int main()
{
int choice,n,i,factorial;
float a,b,c,d,x1,x2;
do
{
printf("1. linear equation\n");
printf("2. factorial\n");
printf("3. quadratic equation\n");
printf("4. exit\n");
printf("enter choice :\n");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("enter the values of a and b:");
scanf("%f %f",&a,&b);

if(a==0)
{
if(b==0)
printf("infinite solutions\n");
else
printf("no solution\n");
}
else
printf("x=%.2f\n",-b/a);
break;

case 2:
printf("enter a number from (0 to 12):");
scanf("%d",&n);

if(n<0||n>12)
  printf("invalid number\n");
else
{
factorial=1;
for(i=1;i<=n;i++)
factorial = factorial*i;
printf("factorial = %d\n",factorial);
}
break;

case 3:
printf("enter a,b,c :");
scanf("%f%f%f",&a,&b,&c);

if(a==0)
printf("it is not a quadratic equation \n ");
else
{
d = b*b-4*a*c;
if(d>0)
{
x1 = (-b+sqrt(d))/(2*a);
x2 = (-b-sqrt(d))/(2*a);

printf("roots = %.2f %.2f\n",x1,x2);
}
else if(d==0)
{
x1 = -b/(2*a);
printf("equal roots = %.2f\n",x1);
}
else
printf("no real roots\n");
}
break;
case 4:
printf("program completed\n");
break;

default:
printf("invalid choice,try again\n");
}
}
while(choice !=4);
return 0;
}
