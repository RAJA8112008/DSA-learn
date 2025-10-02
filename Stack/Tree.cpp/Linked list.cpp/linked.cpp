#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at end (for testing)
void insertAtEnd(struct Node** head, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;

    if (*head == NULL) {
        *head = newnode;
        newnode->next = *head;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = *head;
}

// Delete node at given position (1-based)
void deleteNode(struct Node** head, int pos) {
     struct node* temp=*head;
     if(pos==1){
      if(temp->next=head){
        free(temp);
        return NULL;
      }
     }
     //at any pos 
     int count=1;
     while(count<pos-1 && temp->next!=head){
      temp=temp->next;
      count++;
     }
     struct node* del=temp->next;
     temp->next=del->next;
     del->prev=NULL;
     free(del);
}

// Display circular linked list
void display(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
     
    // printf("Original CLL: ");
    // display(head);

    // deleteNode(&head, 1); // delete first node
    // printf("After deleting position 1: ");
    // display(head);

    // deleteNode(&head, 3); // delete last node
    // printf("After deleting position 3: ");
    // display(head);

    return 0;
}
