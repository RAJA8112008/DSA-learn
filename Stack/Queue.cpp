#include<iostream>
using namespace std;
class CirQueue{
    public:
   int *arr;
   int size;
   int front;
   int rear;
   CirQueue(int size){
   this->size=size;
   arr=new int[size];
      front=-1;
      rear=-1;
   }
   void push(int data){
        if((rear + 1 == front) ||(front==0 && rear==size-1)){
            cout<<"Queue is full"<<endl;
            return;
        } else if(rear==-1){
            rear=0;
            front=0;
            arr[rear]=data;
           
        }else if(rear==size-1 && front!=0){
              rear=0;
              arr[rear]=data;
            
        }else{
            rear++;
           arr[rear] =data;
        //    rear++;
        }
   }
   void pop(){
    if(front==-1){
     cout<<"Queue is empty"<<endl;
     return;
    }else if(front==rear){
       arr[front]=-1;
       front=-1;
    rear=-1;
    }else if(front=size-1){
          arr[front]=-1;
      front=0;    
    }else{
        arr[front]=-1;
        front++;
    }
   }
   void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear)
            break;

        // manual wrap around
        if (i == size - 1)
            i = 0;
        else
            i++;
    }
    cout << endl;
}

};
int main(){
CirQueue q(10);
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.display();
q.pop();
q.display();

}
