#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at end (for creating DLL easily)
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete at beginning
// void deleteAtBeginning(struct Node** head) {
//     if (*head == NULL) {
//         printf("DLL is empty, nothing to delete!\n");
//         return;
//     }
//     struct Node* temp=*head;
//     if(temp->next!=NULL){
//         (*head)=temp->next;
//     }
//     (*head)->prev=NULL;
//     free(temp);
// }
//     struct Node* temp = *head;

//     *head = temp->next;  // move head to next node
//     if (*head != NULL) {
//         (*head)->prev = NULL;
//     }

//     printf("Deleted element: %d\n", temp->data);
//     free(temp);
// }
  void deleteAtend(struct Node**head){
    struct Node* temp=*head;
    while(temp->next!=NULL){
            temp=temp->next;
    }
    temp->prev->next=NULL;
    temp->prev=NULL;
    free(temp);
  }

// Display DLL
void display(struct Node* head) {
    struct Node* temp = head;
    printf("DLL: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create DLL
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    display(head);

    // Delete nodes from beginning
   deleteAtend(&head);
    display(head);

    deleteAtend(&head);
    display(head);

   deleteAtend(&head);
    display(head);

    deleteAtend(&head);  // trying again when empty

    return 0;
}
