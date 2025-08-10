 #include <stdio.h>
#include <string.h>

#define MAX 5 // Max number of print jobs

struct PrintJob {
    int jobID;
    char docName[50];
    int pages;
};

struct PrintJob queue[MAX];
int front = 0, rear = 0;

// Add new job
void addJob() {
    if (rear == MAX) {
        printf("Queue is full!\n");
        return;
    }
    printf("Enter Job ID: ");
    scanf("%d", &queue[rear].jobID);
    printf("Enter Document Name: ");
    scanf("%s", queue[rear].docName);
    printf("Enter Number of Pages: ");
    scanf("%d", &queue[rear].pages);
    rear++;
    printf("Job added successfully!\n");
}

// Process job
void processJob() {
    if (front == rear) {
        printf("No jobs to process!\n");
        return;
    }
    printf("Processing Job: %d, %s, %d pages\n",
           queue[front].jobID,
           queue[front].docName,
           queue[front].pages);
    front++;
}

// View all jobs
void viewJobs() {
    if (front == rear) {
        printf("No pending jobs.\n");
        return;
    }
    printf("Pending Jobs:\n");
    for (int i = front; i < rear; i++) {
        printf("%d: %s (%d pages)\n", queue[i].jobID, queue[i].docName, queue[i].pages);
    }
}

// Calculate total pages
void totalPages() {
    int total = 0;
    for (int i = front; i < rear; i++) {
        total += queue[i].pages;
    }
    printf("Total Pages Pending: %d\n", total);
}

int main() {
    int choice;
    do {
        printf("\n--- Print Job Management ---\n");
        printf("1. Add Job\n");
        printf("2. Process Job\n");
        printf("3. View Jobs\n");
        printf("4. Total Pages\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addJob(); break;
            case 2: processJob(); break;
            case 3: viewJobs(); break;
            case 4: totalPages(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}