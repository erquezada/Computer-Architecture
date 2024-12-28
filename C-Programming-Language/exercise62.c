#include <stdio.h>

int DAYS_IN_MONTH_NORMAL[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int DAYS_IN_MONTH_LEAP[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(int month, int day, int leap_year) {
    // Validate the month and day
    if (month < 1 || month > 12) {
        printf("Error: Invalid month value. Must be between 1 and 12.\n");
        return -1;
    }

    // Select the appropriate array for days in month
    int *days_in_month = leap_year ? DAYS_IN_MONTH_LEAP : DAYS_IN_MONTH_NORMAL;

    if (day < 1 || day > days_in_month[month - 1]) {
        printf("Error: Invalid day value. Day must be between 1 and %d for month %d.\n", days_in_month[month - 1], month);
        return -1;
    }

    // Calculate the day of the year
    int i, total_days = 0;
    for (i = 0; i < month - 1; i++) {
        total_days += days_in_month[i];
    }
    total_days += day;
    
    return total_days;
}

void month_day(int year_day, int leap_year) {
    // Validate the day of the year
    int total_days_in_year = leap_year ? 366 : 365;
    if (year_day < 1 || year_day > total_days_in_year) {
        printf("Error: Invalid day of the year. Must be between 1 and %d.\n", total_days_in_year);
        return;
    }

    // Select the appropriate array for days in month
    int *days_in_month = leap_year ? DAYS_IN_MONTH_LEAP : DAYS_IN_MONTH_NORMAL;
    int month = 0, day = 0;

    // Find the month and day corresponding to the year day
    while (year_day > days_in_month[month]) {
        year_day -= days_in_month[month];
        month++;
    }
    day = year_day;

    printf("Month: %d, Day: %d\n", month + 1, day);
}

int main() {
    int month = 2, day = 30, leap_year = 1;  // Example input (February 30th)
    int day_of_year_result = day_of_year(month, day, leap_year);
    
    if (day_of_year_result != -1) {
        printf("Day of the year: %d\n", day_of_year_result);
    }

    int year_day = 366;  // Example input (366th day of the year in a leap year)
    month_day(year_day, leap_year);

    return 0;
}