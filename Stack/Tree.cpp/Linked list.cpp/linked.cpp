#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* point;
    Node(int data){
        this->data = data;
        this->point = NULL;
    }
};

// insert at tail
void insertAttail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->point = temp;
    tail = temp;
}

// deletion of any node
void deleteNode(int position, Node* &head) {
    if(position == 1) {
        Node* temp = head;
        head = head->point;
        temp->point = NULL;
        delete temp;
    }
    else {
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;

        while(cnt < position && curr != NULL) {
            prev = curr;
            curr = curr->point;
            cnt++;
        }

        if(curr == NULL) return; // invalid position

        prev->point = curr->point;
        curr->point = NULL;
        delete curr;
    }
}

// insertion at head
void insertAthead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->point = head;
    head = temp;
}

// insert at position
void insertAtposition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAthead(head,data);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->point;
        cnt++;
    }
    if(temp->point == NULL){
        insertAttail(tail,data);
        return;
    }
    Node* node = new Node(data);
    node->point = temp->point;
    temp->point = node;
}

// print linked list
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->point;
    }
    cout << endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAttail(tail,20);
    print(head);
    insertAttail(tail,30);
    print(head);
    insertAttail(tail,40);
    print(head);
    insertAtposition(head,tail,3,50);
    print(head);

    deleteNode(5,head);   
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
}
