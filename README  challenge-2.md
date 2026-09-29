statement:A student is planning a road trip. Write a C program to read the total distance to be travelled (in kilometres), the vehicle's mileage (kilometres per litre), and the current fuel price per litre. Calculate and display the amount of fuel required for the trip and the total fuel cost 
ALGORITHM
1.start
2.take float totaldistance,mileage,fuelprice
3.take float fuelrequired,totalfuelcost
5.read totaldistance,mileage,fuelprice
6.fuelrequired = totaldistance/mileage
7.totalfuelcost = fuelrequired*fuelprice
8.print the fuelrequired,totalfuelcost
9.stop

PROGRAM:
#include<stdio.h>
int main() {
float totaldistance,mileage,fuelprice;
float fuelrequired,totalfuelcost;
printf("enter the totaldistance (km) :");
scanf("%f",&totaldistance);
printf("enter the mileage (km/litre) :");
scanf("%f",&mileage);
printf("enter the fuelprice (Rs/litre) :");
scanf("%f",&fuelprice);
fuelrequired = totaldistance/mileage;
totalfuelcost = fuelrequired*fuelprice;
printf("fuelrequired = %.2f litres\n",fuelrequired);
printf("totalfuelcost= Rs %.2f\n",totalfuelcost);
return 0;
}
