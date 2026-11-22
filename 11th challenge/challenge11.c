#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage, int *total,float *average, int *peakUsage,int *peakDay);
void detectWaterAlerts(int *zoneUsage, int dailyTarget,int *overLimitDays, int *totalExcess,int *spikeDays, int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS],int dailyTarget[ZONES],int excessByZone[ZONES],int overLimitByZone[ZONES],int spikeByZone[ZONES],
                         int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES],int spikeByZone[ZONES],int excessByZone[ZONES]);
int readInteger(char prompt[], int min, int max)
{
int value, ch;
while (1)
{
printf("%s", prompt);
if (scanf("%d", &value) != 1)
{
printf("Invalid input! Enter an integer.\n");
while ((ch = getchar()) != '\n' && ch != EOF);
continue;
}
while ((ch = getchar()) != '\n' && ch != EOF);
if (value < min || value > max)
{
printf("Invalid value! Enter between %d and %d.\n",min, max);
}
else
{
return value;
}}}
void inputWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES])
{
int i, j;
printf("\n ENTER WATER CONSUMPTION DATA \n");
for (i = 0; i < ZONES; i++)
{
printf("\nZone %d\n", i + 1);
dailyTarget[i] = readInteger("Enter daily target (100-50000 litres): ",100, 50000);
for (j = 0; j < DAYS; j++)
{
char prompt[100];
sprintf(prompt, "Enter Day %d consumption: ", j + 1);
usage[i][j] = readInteger(prompt, 0, 50000);
}}}
void displayWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES])
{
int i, j;
printf("\n WATER CONSUMPTION MATRIX \n");
printf("Zone\t");
for (j = 0; j < DAYS; j++)
printf("Day%d\t", j + 1);
printf("Target\n");
for (i = 0; i < ZONES; i++)
{
printf("Zone%d\t", i + 1);
for (j = 0; j < DAYS; j++)
{
printf("%d\t", usage[i][j]);
}
printf("%d\n", dailyTarget[i]);
}}
void calculateZoneStats(int *zoneUsage, int *total,float *average, int *peakUsage,int *peakDay)
{
int day;
*total = 0;
*peakUsage = *zoneUsage;
*peakDay = 1;
for (day = 0; day < DAYS; day++)
{
*total += *(zoneUsage + day);
if (*(zoneUsage + day) > *peakUsage)
{
*peakUsage = *(zoneUsage + day);
*peakDay = day + 1;
}}
*average = (float)(*total) / DAYS;
}
void detectWaterAlerts(int *zoneUsage, int dailyTarget,int *overLimitDays, int *totalExcess,int *spikeDays, int *alertDays)
{
int day;
int alert;
*overLimitDays = 0;
*totalExcess = 0;
*spikeDays = 0;
*alertDays = 0;
for (day = 0; day < DAYS; day++)
{
alert = 0;
if (*(zoneUsage + day) > dailyTarget)
{
(*overLimitDays)++;
*totalExcess +=*(zoneUsage + day) - dailyTarget;
alert = 1;
}
if (day > 0)
{
if (*(zoneUsage + day) >*(zoneUsage + day - 1) * 1.40f)
{
(*spikeDays)++;
alert = 1;
}}
if (alert == 1)
{
(*alertDays)++;
}}}
void generateAuditReport(int usage[ZONES][DAYS],int dailyTarget[ZONES],int excessByZone[ZONES],int overLimitByZone[ZONES],int spikeByZone[ZONES],
                         int alertByZone[ZONES])
{
int i;
int total, peakUsage, peakDay;
int average;
float avg;
int spikeDays, alertDays;
printf("\n WATER AUDIT REPORT \n");
for (i = 0; i < ZONES; i++)
    {
calculateZoneStats(&usage[i][0], &total, &avg,&peakUsage, &peakDay);
detectWaterAlerts(&usage[i][0],dailyTarget[i],&overLimitByZone[i],&excessByZone[i],&spikeDays,&alertDays);
spikeByZone[i] = spikeDays;
alertByZone[i] = alertDays;
printf("\nZone %d\n", i + 1);
printf("Weekly Total: %d litres\n", total);
printf("Daily Average: %.2f litres\n", avg);
printf("Highest Consumption: %d litres\n", peakUsage);
printf("Peak Days: Day %d\n", peakDay);
printf("Over-limit Days: %d\n",overLimitByZone[i]);
printf("Total Excess: %d litres\n",excessByZone[i]);
printf("Sudden Spike Days: %d\n",spikeByZone[i]);
printf("Unique Alert Days: %d\n",
alertByZone[i]);
}}
void rankZones(int excessByZone[ZONES])
{
int i, j;
int rank[ZONES];
printf("\n ZONE RANKING \n");
for (i = 0; i < ZONES; i++)
{
rank[i] = 1;
for (j = 0; j < ZONES; j++)
{
if (excessByZone[j] > excessByZone[i])
{
rank[i]++;
}}}
for (i = 1; i <= ZONES; i++)
{
for (j = 0; j < ZONES; j++)
{
if (rank[j] == i)
{
printf("Rank %d : Zone %d - %d litres excess\n",rank[j], j + 1, excessByZone[j]);
}}}}
void displayConservationActions(int overLimitByZone[ZONES],int spikeByZone[ZONES],int excessByZone[ZONES])
{
int i;
printf("\n CONSERVATION ACTIONS \n");
for (i = 0; i < ZONES; i++)
{
printf("\nZone %d:\n", i + 1);
if (spikeByZone[i] > 0)
{
printf("- Check for leaks or unexpected water use.\n");
}
if (overLimitByZone[i] >= 3)
{
printf("- Prioritize a water audit and reduction plan.\n");
}
else if (overLimitByZone[i] >= 1)
{
printf(" Monitor usage and inspect taps or valves.\n");
}
else{
printf(" Maintain water-saving practices.\n");
}
printf("Total excess consumption: %d litres\n",excessByZone[i]);
    }
}
int main()
{
int usage[ZONES][DAYS];
int dailyTarget[ZONES];
int excessByZone[ZONES] = {0};
int overLimitByZone[ZONES] = {0};
int spikeByZone[ZONES] = {0};
int alertByZone[ZONES] = {0};
int choice;
int reportGenerated = 0;
printf("\n WATERWISE AUDIT SYSTEM\n");
inputWaterData(usage, dailyTarget);
while (1)
{
printf("\n MAIN MENU \n");
printf("1. Display Water Data\n");
printf("2. Generate Audit Report\n");
printf("3. Rank Zones by Excess\n");
printf("4. Conservation Actions\n");
printf("5. Exit\n");
choice = readInteger("Enter your choice: ", 1, 5);
switch (choice)
{
case 1:
displayWaterData(usage, dailyTarget);
break;
case 2:
generateAuditReport(usage, dailyTarget,excessByZone,overLimitByZone,spikeByZone,alertByZone);
reportGenerated = 1;
break;
case 3:
if (reportGenerated)
{
rankZones(excessByZone);
}
else
{
printf("\nGenerate the audit report first!\n");
}
break;
case 4:
if (reportGenerated)
{
displayConservationActions(overLimitByZone,spikeByZone,excessByZone);
}else
{
printf("\nGenerate the audit report first!\n");
}
break;
case 5:
printf("\nThank you for using WATERWISE\n");
return 0;
default:
printf("Invalid choice!\n");
}
}
return 0;
}
