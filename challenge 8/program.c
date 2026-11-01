#include<stdio.h>
int main(){
int a[6][6],n,limit;
int i,j,sum;
int row=0,column=0,count=0;
int d1=0,d2=0;
int breadth=0,height=0;
int biggest,edge=0,hot=0;
printf("enter the grid size: ");
scanf("%d",&n);

if(n<3||n>6)
{
printf("enter the number from 3to 4");
return 0;
}
printf("enter the grid values: \n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);

if(a[i][j]<0||a[i][j]>100)
{
printf("invalid ");
return 0;
}}}
printf("enter warning limit: ");
scanf("%d",&limit);

if(limit<1||limit>100)
{
printf("wrong limit");
return 0;
}
printf("\nentered grid:\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
printf("%4d",a[i][j]);
printf("\n");
}
printf("\n row totals:\n");

for(i=0; i<n; i++)
{
sum=0;
for(j=0;j<n;j++)
{
sum=sum+a[i][j];
}
printf("row %d = %d\n",i+1,sum);

if(sum>row)
row = sum;
}
printf("highest row total = %d\n", row);
printf("\ncolumn total :\n");
{
sum=0;
for(i=0;i<n;i++)
{
sum=sum+a[i][j];
}
printf("column %d = %d\n",j+1,sum);

if(sum>column)
{
column=sum;
}
}
printf("highest column total = %d\n",column);
biggest = a[0][0];

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]> biggest)
biggest=a[i][j];

if(a[i][j]>=limit)
count++;
}
}
printf("\n highest value = %d\n",biggest);
printf("position of highest value : \n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]== biggest)
printf("%d%d",i+1,j+1);
}}
printf("\n values meeting limit = %d\n",count);

for(i=0;i<n;i++)
{
d1=d1+a[i][i];
d2=d2+a[i][n-1-i];
}
printf("\nFirst diagonal = %d\n", d1);
printf("Second diagonal = %d\n", d2);
if (d1 == d2)
printf("Both diagonals are equal\n");
else
printf("Both diagonals are different\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==0||j==0||i==n-1||j==n-1)
edge=edge+a[i][j];
}}
printf("\nboundary total =%d\n", edge);

for (i = 1; i < n - 1; i++)
{
for (j = 1; j < n - 1; j++)
{
if (a[i][j] > a[i-1][j] &&
a[i][j] > a[i+1][j] &&
a[i][j] > a[i][j-1] &&
a[i][j] > a[i][j+1])
{
printf("hotspot found at %d%d\n",i+1,j+1);
hot++;
}}}
if(hot==0)
printf("no hotspot found\n");
printf("\nfinal result:");

if(hot>0)
printf("critical");
else if(count>0)
printf("warning");
else
printf("normal");

return 0;
}
