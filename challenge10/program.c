#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputData(float temp[5][7], float humid[5][7], int aqi[5][7]);
void displayData(float temp[5][7], float humid[5][7], int aqi[5][7]);
void calculateAverages(float temp[5][7], float humid[5][7], int aqi[5][7], float avgT[5], float avgH[5], float avgA[5]);
void detectRiskZones(float temp[5][7], float humid[5][7], int aqi[5][7], int risk[5]);
void computeGreenIndex(float avgT[5], float avgH[5], float avgA[5], float green[5]);
void displayRanking(float green[5]);
void displayRecommendations(float avgT[5], float avgH[5], float avgA[5], int risk[5]);
int main()
{
float temp[5][7], humid[5][7];
float avgT[5], avgH[5], avgA[5], green[5];
int aqi[5][7], risk[5];
int choice, ready = 0;
do {
printf("\n1.Input Data");
printf("\n2.Display Data");
printf("\n3.Averages");
printf("\n4.Risk Days");
printf("\n5.Green Index and Ranking");
printf("\n6.Recommendations\n");
printf("7.Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
inputData(temp, humid, aqi);
ready = 1;
break;
case 2:
if(ready)
displayData(temp, humid, aqi);
else
printf("Enter data !\n");
break;
case 3:
if(ready) {
calculateAverages(temp, humid, aqi, avgT, avgH, avgA);
for(int i=0; i<5; i++)
printf("\nZone %d: Temp=%.2f Humidity=%.2f AQI=%.2f\n", i+1, avgT[i], avgH[i], avgA[i]);
} else
printf("Enter data !\n");
break;
case 4:
if(ready)
detectRiskZones(temp, humid, aqi, risk);
else printf("Enter data !\n");
break;
case 5:
if(ready) {
calculateAverages(temp, humid, aqi, avgT, avgH, avgA);
computeGreenIndex(avgT, avgH, avgA, green);
displayRanking(green);
}
else
printf("Enter data !\n");
break;
case 6:
if(ready) {
calculateAverages(temp, humid, aqi, avgT, avgH, avgA);
detectRiskZones(temp, humid, aqi, risk);
displayRecommendations(avgT, avgH, avgA, risk);
} else printf("Enter data !\n");
break;
case 7:
printf("Thanks!\n");
break;
default:
printf("Invalid !\n");
}
} while(choice != 7);
return 0;
}

void inputData(float temp[5][7], float humid[5][7], int aqi[5][7])
{
for(int i=0; i<5; i++)
{
printf("\nZone %d\n", i+1);
for(int j=0; j<7; j++)
{
do {
printf("Day %d Temperature: ", j+1);
scanf("%f", &temp[i][j]);
} while(temp[i][j]<10 || temp[i][j]>50);

do {
printf("Humidity: ");
scanf("%f", &humid[i][j]);
} while(humid[i][j]<0 || humid[i][j]>100);

do {
printf("AQI: ");
scanf("%d", &aqi[i][j]);
} while(aqi[i][j]<0 || aqi[i][j]>500);
}
}
}

void displayData(float temp[5][7], float humid[5][7], int aqi[5][7])
{
printf("\nTEMPERATURE MATRIX\n");
for(int i=0; i<5; i++) {
for(int j=0; j<7; j++)
printf("%.1f ", temp[i][j]);
printf("\n");
}
printf("\nHUMIDITY MATRIX\n"); for(int i=0; i<5; i++)
{
for(int j=0; j<7; j++)
printf("%.1f ", humid[i][j]);
printf("\n");
}
printf("\nAQI MATRIX\n");
for(int i=0;i<5;i++) {
for(int j=0;j<7;j++)
printf("%d ", aqi[i][j]);
printf("\n");
}
}

void calculateAverages(float temp[5][7], float humid[5][7], int aqi[5][7], float avgT[5], float avgH[5], float avgA[5])
{
for(int i=0; i<5; i++)
{
float sumT = 0, sumH = 0, sumA = 0;
for(int j=0; j<7; j++) {
sumT += temp[i][j];
sumH += humid[i][j];
sumA += aqi[i][j];
}
avgT[i] = sumT / 7;
avgH[i] = sumH / 7;
avgA[i] = sumA / 7;
}
}
void detectRiskZones(float temp[5][7], float humid[5][7], int aqi[5][7], int risk[5])
{
for(int i=0; i<5; i++)
{
risk[i] = 0;
printf("\nZone %d Risk Days: ", i+1);
for(int j=0; j<7; j++)
{
if(aqi[i][j] > 150 || temp[i][j] > 35 || humid[i][j] > 80)
{
risk[i]++;
printf("%d ", j+1);
}
}
if(risk[i] == 0)
printf("None");
printf("\nTotal: %d\n", risk[i]);
}
}
void computeGreenIndex(float avgT[5], float avgH[5], float avgA[5], float green[5])
{
for(int i=0; i<5; i++)
{
float x = 100 - avgA[i]/5;
float y = 100 - 4*(avgT[i]>25 ? avgT[i]-25 : 25-avgT[i]);
float z = 100 - 2*(avgH[i]>50 ? avgH[i]-50 : 50-avgH[i]);
if(x < 0) x = 0;
if(y < 0) y = 0;
if(z < 0) z = 0;
green[i] = 0.4*x + 0.3*y + 0.3*z;
}
}void displayRanking(float green[5])
{
int rank[5];
for(int i=0; i<5; i++) {
rank[i] = 1;
for(int j=0; j<5; j++)
if(green[j] > green[i])
rank[i]++;
}
printf("\nGREEN INDEX RANKING\n");
for(int i=0; i<5; i++)
printf("Zone %d: %.2f Rank %d\n", i+1, green[i], rank[i]);
}
void displayRecommendations(float avgT[5], float avgH[5], float avgA[5], int risk[5])
{
for(int i=0; i<5; i++)
{
int found = 0;
printf("\nZone %d:\n", i+1);

if(avgA[i] > 150) {
printf("Reduce vehicle idling .\n");
found = 1;
}
if(avgT[i] > 35)
{
printf("Provide shade .\n");
found = 1;
}
if(avgH[i] > 80) {
printf("Check ventilation .\n");
found=1;
}
if(found==0 && risk[i]>0)
printf("Review individual risk days.\n");
if(risk[i]==0)
printf("Continue monitoring.\n");
}
}
