#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// insert at tail (move it before using)
void insertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    if (tail != NULL) {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    } else {
        tail = temp;  // if tail is null, assign directly
    }
}

// insert at head
void insertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    if (head != NULL) {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}

// insert at position
void insertAtposition(Node*& head, Node*& tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        if (tail == NULL) tail = head; // if list was empty
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    // insert at end 
    if (temp->next == NULL) {
        insertAtTail(tail, data);
        return;
    }

    // insert in middle
    Node* newnode = new Node(data);
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}
 //deletion 
 void deleteNode(){
    
 }
void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 15);
    insertAtTail(tail, 20);
    insertAtTail(tail, 25);
    print(head);  

    insertAtposition(head, tail, 2, 12);
    print(head);  

    insertAtposition(head, tail, 1, 5);
    print(head);  

    insertAtposition(head, tail, 10, 30);
    print(head);  
}
