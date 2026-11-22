#include <stdio.h>
#define zones 5
#define days 7

char *names[] = {"Academic Block", "Hostel", "Library","Cafeteria", "Sports Complex"};

void inputWaterData(int usage[zones][days], int target[zones])
{
int i, j;
for(i=0; i<zones; i++)
{
printf("\n%s\n", names[i]);
for(j=0; j<days; j++)
{
do {
printf("Enter Day %d usage: ", j+1);
scanf("%d", &usage[i][j]);
} while(usage[i][j]<0 || usage[i][j]>50000);
}
do {
printf("Enter daily target: ");
scanf("%d", &target[i]);
} while(target[i]<100 || target[i]>50000);
}
}
void displayWaterData(int usage[zones][days], int target[zones])
{
int i,j;
printf("\nZone\t\t");
for(j=0; j<days; j++)
printf("D%d\t", j+1);
printf("Target\n");
for(i=0; i<zones; i++)
{
printf("%-16s", names[i]);
for(j=0; j<days; j++)
printf("%d\t", usage[i][j]);
printf("%d\n", target[i]);
}
}
void calculateZoneStats(int *p, int *total, float *avg,int *peak, int *day)
{
int i;
*total=0;
*peak=*p;
*day=1;

for(i=0; i<days; i++)
{
*total += *(p+i);
if(*(p+i)>*peak)
{
*peak=*(p+i);
*day=i+1;
}
}
*avg=(float)*total/days;
}

void detectWaterAlerts(int *p, int target, int *over,int *excess, int *spike, int *alert)
{
int i, a, b;
*over=0; *excess=0; *spike=0; *alert=0;
for(i=0; i<days; i++)
{
a=0; b=0;
if(*(p+i)>target)
{
a=1;
(*over)++;
*excess += *(p+i)-target;
}
if(i>0 && *(p+i)*100 > *(p+i-1)*140)
{
b=1;
(*spike)++;
}
if(a || b)
(*alert)++;
}
}

void generateAuditReport(int usage[zones][days], int target[zones],int excess[zones], int over[zones],int spike[zones], int alert[zones])
{
int i,total,peak,day;
float avg;
for(i=0; i<zones; i++)
{
calculateZoneStats(&usage[i][0], &total, &avg, &peak, &day);
detectWaterAlerts(&usage[i][0], target[i],&over[i], &excess[i], &spike[i], &alert[i]);
printf("\n%s\n", names[i]);
printf("Weekly Total: %d\n", total);
printf("Daily Average: %.2f\n", avg);
printf("Highest Usage: %d\n", peak);
printf("Highest Usage Day: %d\n", day);
printf("Over-limit Days: %d\n", over[i]);
printf("Total Excess: %d\n", excess[i]);
printf("Sudden Spikes: %d\n", spike[i]);
printf("Alert Days: %d\n", alert[i]);
}
}

void rankZones(int excess[zones])
{
int i,j,rank,max=0;
for(i=0; i<zones; i++)
if(excess[i]>max)
max=excess[i];
printf("\nZones with highest excess (%d litres):\n",max);

for(i=0; i<zones; i++)
if(excess[i]==max)
printf("%s\n",names[i]);

printf("\nZone Rankings:\n");

for(i=0; i<zones; i++)
{
rank=1;

for(j=0; j<zones; j++)
if(excess[j]>excess[i])
rank++;

printf("%s - Rank %d\n",names[i],rank);
}
}

void displayConservationActions(int over[zones],
                                int spike[zones], int excess[zones])
{
int i;

for(i=0; i<zones; i++)
{
printf("\n%s:\n",names[i]);

if(spike[i]>0)
printf("Check for leaks or unusual usage.\n");

if(over[i]>=3)
printf("Conduct a water audit and reduce usage.\n");
else if(over[i]>0)
printf("Check taps and valves.\n");

if(over[i]==0 && spike[i]==0)
printf("Maintain good practices.\n");

printf("Excess: %d litres\n",excess[i]);
}
}

int main()
{
int usage[zones][days], target[zones];
int excess[zones]={0}, over[zones]={0};
int spike[zones]={0}, alert[zones]={0};
int choice, done=0;

inputWaterData(usage,target);

do {
printf("\n===== WATERWISE MENU =====\n");
printf("1. Display Water Data\n");
printf("2. Generate Audit Report\n");
printf("3. Rank Zones by Excess\n");
printf("4. Conservation Actions\n");
printf("5. Exit\n");

printf("Enter choice: ");
scanf("%d",&choice);

switch(choice)
{
case 1:
displayWaterData(usage,target);
break;

case 2:
generateAuditReport(usage,target,excess,over,spike,alert);
done=1;
break;

case 3:
if(done)
rankZones(excess);
else
printf("Generate report first!\n");
break;

case 4:
if(done)
displayConservationActions(over,spike,excess);
else
printf("Generate report first!\n");
break;

case 5:
printf("Thank you for using WATERWISE!\n");
break;

default:
printf("Invalid choice!\n");
}
} while(choice!=5);

return 0;
}
