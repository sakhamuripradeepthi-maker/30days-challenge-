#include<stdio.h>
int main(){
float distance,mileage,fuelprice,fuelrequired,fuelcost;
printf("enter the distance:");
scanf("%f", &distance);
printf("enter the mileage:");
scanf("%f", &mileage);
printf("enter the fuel:");
scanf("%f", &fuelprice);
fuelrequired=(distance/mileage);
fuelcost=(fuelrequired*fuelprice);
printf("total fuelrequired =%f\n",fuelrequired);
printf("total fuelcost =%f\n",fuelcost);
return 0;
}
