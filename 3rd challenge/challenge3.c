#include<stdio.h> 
int main()
{
float purchase, discount, discountAmount;
float amountAfterDiscount, delivery, distance, finalAmount;
int customerType;
printf("Enter purchase amount: Rs. ");
scanf("%f", &purchase);
printf("Enter customer type (1 = Student, 2 = Regular): ");
scanf("%d", &customerType);
printf("Enter delivery distance in km: ");
scanf("%f", &distance);

if (customerType == 1)
 {
if (purchase >= 2000)
discount = 15;
else
discount = 10;
}
else if (customerType == 2)
{
if (purchase >= 3000)
discount = 8;
else
discount = 0;
}
else {
printf("Invalid customer type!\n");
}
discountAmount = purchase * discount / 100;
amountAfterDiscount = purchase - discountAmount;

if (distance <= 5)
delivery = 40;
else if (distance <= 15)
delivery = 70;
else
delivery = 100;
finalAmount = amountAfterDiscount + delivery;
printf("\n----- SMARTCART BILL -----\n");
printf("Discount Amount: Rs. %.2f\n", discountAmount);
printf("Amount After Discount: Rs. %.2f\n",amountAfterDiscount);
printf("Delivery Charge: Rs. %.2f\n", delivery);
printf("Final Payable Amount: Rs. %.2f\n", finalAmount);
return 0;
}
