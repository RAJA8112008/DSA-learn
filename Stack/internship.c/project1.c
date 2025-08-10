#include <stdio.h>

int main() {
    int a[4][5] = {
        {1, 1, 1, 1, 1}, // Employee 0
        {1, 0, 1, 1, 1}, // Employee 1
        {0, 0, 1, 1, 0}, // Employee 2
        {1, 1, 1, 1, 1}  // Employee 3
    };

    char *dayName[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // 1. Total attendance per employee
    printf("Total attendance per employee: [");
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += a[i][j];
        }
        printf("%d", sum);
        if (i < 3) printf(", "); // comma between employees
    }
    printf("]\n");

    // 2. Perfect attendance employees
    printf("Perfect attendance: Employee [");
    int firstPrinted = 0; // to handle commas
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += a[i][j];
        }
        if (sum == 5) { // 5 means attended all days
            if (firstPrinted) printf(", ");
            printf("%d", i);
            firstPrinted = 1;
        }
    }
    printf("]\n");
// Day with lowest attendance
    int minDay = 0;
    int minSum = 4;  // max attendance per day = number of employees
    for (int j = 0; j < 5; j++) {
        int sum = 0;
        for (int i = 0; i < 4; i++)
            sum += a[i][j];
        if (sum < minSum) {
            minSum = sum;
            minDay = j;
        }
    }
    printf("Day with lowest attendance: Day %d (%s)\n", minDay, dayName[minDay]);

    return 0;
}