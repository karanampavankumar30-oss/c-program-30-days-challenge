#include <stdio.h>
#define rows 5
#define columns 8

void arrangingseats(int seats[rows][columns]);
void displayseats(int seats[rows][columns]);
int bookseat(int seats[rows][columns],int row,int column);
int cancelseat(int seats[rows][columns],int row,int column);
int reservegroup(int seats[rows][columns],int row,int column);
void displayreport(int seats[rows][columns]);
int size;
int main()
{
int seats[rows][columns];
int choice,row,column,size,result;

do
{
printf("\n seatsmart menu \n");
printf("1. display seats\n");
printf("2. book seat\n");
printf("3. cancel booking\n");
printf("4. group resrvation\n");
printf("5. occupancy report\n");
printf("6. exit\n");
printf("enter choice: ");
scanf("%d",&choice);

if(choice == 1)
{
displayseats(seats);
}
else if(choice == 2)
{
printf("enter row(1-5) : ");
scanf("%d",&row);
printf("enter seat (1-8) : ");
scanf("%d",&column);

result = bookseat(seats,row,column);

if(result == 1)
printf("seat booked successfully\n");
else
printf("seat is already booked\n");
}
else if(choice==3)
{
printf("enter row: ");
scanf("%d",&row);
printf("enter seat: ");
scanf("%d",&column);

result = cancelseat(seats,row,column);

if(result==1)
printf("booking cancelled\n");
else
printf("invalid seat \n");
}
else if(choice==4)
{
printf("enter group size(2-8)");
scanf("%d",&size);

result = reservegroup(seats,rows,columns);

if(result == 1)
printf("group booking successful\n");
else
printf("no seats available together\n");
}
else if(choice==5)
{
displayreport(seats);
}
else if(choice==6)
{
printf("thank you\n");
}
else
{
printf("invalid choice\n");

}
}while(choice != 6);
return 0;

void arrangingseats(int seats[rows][columns])
{
int i,j;
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
seats[i][j]=0;
}
}

void displayseats(int seats[rows][columns])
{
int i,j;
printf("\n 0 = available,1 = booked");
for(i=0;i<rows;i++)
{
printf("row %d:",i+1);
}
for(j=0;j=columns;j++)
{
printf("%d",seats[i][j]);
}
printf("\n");
}
}
}

int bookseats(int seats[rows][columns],int row,int column)
{
row--;
column--;
if(row<0||row>rows||column<0||column>columns)
return 0;
if(seats[row][column]==1)
return 0;

seats[row][column] = 1;
return 1;
}
int cancelseat(int seats[rows][columns],int row, int column)
{
row--;
column--;
if(row<0||row>rows||column<0||column>column)
return 0;
if(seats[row][column]==0)
return 0;
seats[row][column]=0;
return 1;
}
int reservegroup(int seats[rows][columns],int row,int column)
{
int i,j,k,free;
if(size < 2|| size>columns)
return 0;
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
free = 1;
for(k=0;k<size;k++)
{
if(seats[i][j+1]==1)
{
free = 0;
break;
}
}
if(free==1)
{
for(k=0;k<size;k++)
{
seats[i][j=+k]=1;
}
printf("seats booked in row %d\n",i+1);
return 1;
}
}
}
return 0;
}
void displayreport(int seats[rows][columns])
{
int i,j,booked = 0,available = 0;
int rowcount[rows]={0};
int max = 0;
float percentage;

for(i=0;i<rows;i++)
{
for(j=0;i<rows;j++)
{
if(seats[i][j]==1)
{
booked++;
rowcount[i]++;
}
else
{
available++;
}
}
}

percentage = (booked/40.0)*100;
printf("\n occupancy report \n");
printf("booked seats:%d\n",booked);
printf("available seats: %d\n",available);
printf("occupancy: %.2f%%\n",percentage);

for(i=0;i<rows;i++)
{
if(rowcount[i]>max)
max = rowcount[i];
}
printf("busiest row: ");

if(max==0)
printf("none\n");
else
{
for(i=0;i<rows;i++)
{
if(rowcount[i]==max)
printf("row %d",i+1);
}
printf("( %d seats booked)\n",max);
}
}
