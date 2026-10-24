#include<stdio.h>
void reverse(int a[],int lt,int rt)
{
int temp;
while(lt<rt)
{
temp=a[lt];
a[lt]=a[rt];
a[rt]=temp;
lt++;
rt--;
}
}
int main()
{
int a[12];
int n,i,k,temp;
int sum=0,min,max;
int s,f=0;
int p=0;
int c=1,lst=1;
int r,d,count=0;
float avg;
do
{
printf("enter no.of readings(5 to 12)\n");
scanf("%d",&n);
if(n<5||n>12)
{
printf("invalid reading,enter again\n");
}
}while(n<5||n>12);
for(i=0;i<n;i++)
{
do{
printf("enter reading %d(0 to 1000)\n",i+1);
scanf("%d",&a[i]);
if(a[i]<0||a[i]>1000)
printf("invalid reading.enter again\n");
}
while(a[i]<0||a[i]>1000);
}
printf("original num:\n");
min=max=a[0];
sum=0;
for(i=0;i<n;i++)
{
printf("%d",a[i]);
sum+=a[i];
if(a[i]<min)
min=a[i];
if(a[i]>max)
max=a[i];
}
avg=sum/n;
printf("Sum = %d\n", sum);
printf("Avg = %.2f\n", avg);
printf("min = %d\n", min);
printf("max = %d\n", max);
s=0;
f=0;
for(i = 0; i < n; i++)
{
if(a[i] < max && (f == 0 || a[i] > s))
{
s = a[i];
f = 1;
}}
if(f == 1)
printf("Second-largest distinct value = %d\n", s);
else
printf("No second-largest distinct value exists\n");
for(i=1;i<n-1;i++)
{
if(a[i]>a[i-1]&&a[i]>a[i+1])
p++;
}
printf("no.of local p=%d\n",p);
c=1,lst=1;
for(i=1;i<n;i++)
{
if(a[i]>a[i-1])
{
c++;
if(c>lst)
lst=c;
}
else{
c=1;
}
}
printf("lst increasing run=%d\n",lst);
printf("enter rotation k:\n");
scanf("%d",&k);
k=k%n;
if(k<0)
k+=n;
if(k>0)
{
reverse(a,0,n-1);
reverse(a,0,k-1);
reverse(a,k,n-1);
}
printf("rotated\n");
for(i=0;i<n;i++)
printf("%d",a[i]);
r=a[n-1];
d=(r%9)+1;
c=0;
for(i=0;i<n;i++)
{
if(a[i]%d==0)
c++;
}
printf("r=%d\n",r);
printf("d=%d\n",d);
printf("no.of values divisible by d=%d\n",c);
return 0;
}

