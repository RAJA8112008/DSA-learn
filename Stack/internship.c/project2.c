 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stop {
    int id;
    char location[50];
    int distance;
    struct Stop *next;
};

int main() {
    struct Stop *head = NULL, *temp, *newStop;
    int choice;

    while (1) {
        printf("\n1. Add Stop at End");
        printf("\n2. Remove Stop by ID");
        printf("\n3. Print Route");
        printf("\n4. Calculate Total Distance");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Add Stop
            newStop = (struct Stop *)malloc(sizeof(struct Stop));
            printf("Enter Stop ID: ");
            scanf("%d", &newStop->id);
            printf("Enter Location Name: ");
            scanf("%s", newStop->location);
            printf("Enter Distance to next stop (km): ");
            scanf("%d", &newStop->distance);
            newStop->next = NULL;

            if (head == NULL) {
                head = newStop;
            } else {
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newStop;
            }
            printf("Stop added!\n");
        }

        else if (choice == 2) {
            // Remove Stop
            int id;
            printf("Enter Stop ID to remove: ");
            scanf("%d", &id);
            temp = head;
            struct Stop *prev = NULL;
            while (temp != NULL && temp->id != id) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("Stop not found!\n");
            } else {
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                free(temp);
                printf("Stop removed!\n");
            }
        }

        else if (choice == 3) {
            // Print Route
            temp = head;
            if (temp == NULL) {
                printf("No stops in route.\n");
            } else {
                printf("Current Route: ");
                while (temp != NULL) {
                    printf("Stop%d(%s)", temp->id, temp->location);
                    if (temp->next != NULL) printf(" -> ");
                    temp = temp->next;
                }
                printf("\n");
            }
        }

        else if (choice == 4) {
            // Calculate Distance
            int total = 0;
            temp = head;
            while (temp != NULL) {
                total += temp->distance;
                temp = temp->next;
            }
            printf("Total Distance: %d km\n", total);
        }

        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}