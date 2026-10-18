#include<stdio.h>
#include<math.h>
int main(){
int ch,n,i;
int a,b,c,d,x;
float root,root1,root2;
int factorial;
do{
printf("1.solve a linear eq(ax+b=0)\n:");
printf("2.calculate factorial(n!)\n:");
printf("3.solve a quadratic eq(a*x*x+bx+c=0)\n:");
printf("4.exit\n");
printf("enter ch:");
scanf("%d",&ch);
switch(ch){
case 1:
{
printf("enter a and b:");
scanf("%d %d",&a,&b);
}
x=(-b/a);
if(a!=0){
printf("x=%d",x);
}
else if(a==0 && b==0){
printf("infinitely many sol");
}
else if(a==0 && b!=0){
printf("no sol");
}
break;
case 2:
{
printf("enter values(0 to 12):");
scanf("%d",&n);
}
for(i=1;i<=12;i++);
factorial *=1;
if(factorial==1){
printf("factorial of num is:%d\n",factorial);
}
if(n<0||n>12){
printf("invaild factorial:");
}
break;
case 3:{
printf("enter a,b and c:");
scanf("%d %d %d",&a,&b,&c);
}
d=b*b-4*a*c;
if(d>0){
root1=(-b+sqrt(d))/(2*a);
root2=(-b-sqrt(d))/(2*a);
printf("roots are real and distinct:");
printf("root1=%.2f\n",root1);
printf("root2=%.2f\n",root2);
}
else if(d==0){
root=-b/(2*a);
printf("equal roots:%.2f\n",root);
}
else{
printf("no real roots:");
}
break;
case 4:{
printf("exit");
 }
}
}while(ch!=4);
return 0;
}
