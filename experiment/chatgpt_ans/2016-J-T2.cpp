#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

// Function to check if a date is palindromic
int isPalindrome(int date) {
    int reverse = 0, original = date;
    while (date > 0) {
        reverse = reverse * 10 + date % 10;
        date /= 10;
    }
    return (original == reverse);
}

int main() {
    int date1, date2;
    int year, month, day;
    int count = 0;

    scanf("%d", &date1);
    scanf("%d", &date2);

    // Loop through all dates between date1 and date2
    for (int date = date1; date <= date2; date++) {
        // Extract year, month, and day from date
        year = date / 10000;
        month = (date / 100) % 100;
        day = date % 100;

        // Check if date is valid
        if (month < 1 || month > 12) {
            continue;
        }
        if (day < 1 || day > 31) {
            continue;
        }
        if (month == 2) {
            if (isLeapYear(year) && day > 29) {
                continue;
            } else if (!isLeapYear(year) && day > 28) {
                continue;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                continue;
            }
        }

        // Check if date is palindrome
        if (isPalindrome(date)) {
            count++;
        }
    }

    printf("%d", count);
    return 0;
}
