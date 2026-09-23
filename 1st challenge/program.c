//A student has marks for five subjects.write a c program to read the marks of all five subjects and calulate the total marks,average marks,percentage.display all three results clearly
#include <stdio.h>
int main(){
int s1,s2,s3,s4,s5;
float total,average,percentage;
printf("Enter the marks for 5subjects: ");
scanf("%d %d %d %d %d", &s1,&s2,&s3,&s4,&s5);
total =s1+s2+s3+s4+s5;
average =total/5;
percentage=(total/500)*100;
printf("Total marks =%f\n",total);
printf("average marks =%f\n",average);
printf("percentage =%f\n",percentage);
return 0;
}
