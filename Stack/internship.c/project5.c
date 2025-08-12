#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int score;
};

int main() {
    int n = 3; // Number of students
    struct Student students[3] = {
        {1, "Sumit", 85},
        {2, "Aditi", 92},
        {3, "Aman", 78}
    };

    // Sorting in descending order (highest score first)
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(students[i].score < students[j].score) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    // Printing with ranks
    printf("Rank\tID\tName\tScore\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\t%d\n", i+1, students[i].id, students[i].name, students[i].score);
    }

    return 0;
}