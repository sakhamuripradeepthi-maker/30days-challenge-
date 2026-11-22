Algorithm
1. Start
2. Declare a 2D array to store water consumption of 5 zones for 7 days and a 1D array to store daily targets.
3. Read the daily water consumption and daily target for each zone.
4. Validate the input values and ask the user to re-enter invalid values.
5. Display the water consumption matrix along with the daily targets.
6. Calculate the weekly total consumption, daily average, highest consumption and peak day for each zone using pointer arithmetic.
7. Compare each day's water consumption with the daily target and calculate the number of over-limit days and total excess consumption.
8. Detect sudden spikes by comparing the current day's consumption with the previous day's consumption. If consumption exceeds 140% of the previous day's consumption, count it as a spike.
9. Calculate the total number of unique alert days for each zone.
10. Generate and display the complete water audit report for all zones.
11. Rank all five zones according to their total excess water consumption in descending order.
12. Display conservation actions based on over-limit days and sudden spikes.
13. Display the main menu with the following options:
    - Display Water Data
    - Generate Audit Report
    - Rank Zones by Excess
    - Conservation Actions
    - Exit
14. Read the user's choice and perform the corresponding operation.
15. If the user selects an invalid option, display an error message.
16. Repeat the menu until the user selects Exit.
17. Stop
