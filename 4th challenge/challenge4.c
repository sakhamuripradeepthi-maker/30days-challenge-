#include <stdio.h>
int main() {
int amo;
int count = 0;
int scount = 0, mcount = 0, lcount = 0;
int stotal = 0, mtotal = 0, ltotal = 0;
int total = 0;
float avg;
printf("Enter expense amo (0 to stop): ");
scanf("%d", &amo);
while (amo != 0) {
if (amo < 0) {
printf("Invalid expense!\n");
}
else {
count++;
total = total + amo;
if (amo < 100) {
scount++;
stotal = stotal + amo;
}
else if (amo < 500) {
mcount++;
mtotal = mtotal + amo;
}
else {
lcount++;
ltotal = ltotal + amo;
}
  }
printf("Enter expense amo (0 to stop): ");
scanf("%d", &amo);
}
printf("Valid expenses: %d\n", count);
printf("Total expenses: %d\n", total);
printf("Small expenses count: %d\n", scount);
printf("Small expenses total: %d\n", stotal);
printf("Medium expenses count: %d\n", mcount);
printf("Medium expenses total: %d\n", mtotal);
printf("Large expenses count: %d\n", lcount);
printf("Large expenses total: %d\n", ltotal);
if (count > 0) {
avg = (float)total / count;
printf("avg expense: %.2f\n", avg);
    }
else {
printf("No valid expenses were entered.\n");
}
return 0;
}

