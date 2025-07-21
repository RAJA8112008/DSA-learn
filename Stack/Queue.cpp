#include<iostream>
using namespace std;
class Queue{
    public:
      int *arr;
      int size;
      int front;
      int rear;
      //constructor
    Queue(int size){
     arr=new int[size];
     this->size=size;
     front=0;
     rear=0;
    }
     void push(int data){
      if(size==rear){
        cout<<"Queue is full"<<endl;
      }else{
         arr[rear]=data;
         rear++;
      }
     }
     void pop(){
      if(front==rear){
         cout<<"Queue is empty"<<endl;
      }else{
         arr[front]=-1;
         front++;
         if(front==rear){
            front=0;
            rear=0;
         }
      }
     }
     bool isEmpty(){
        if(front==rear){
            return true;
        }else{
            return false;
        }
     }
     int getSize(){
        return rear-front;
     }
     int getFront(){
        if(front==rear){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }else{
            return arr[front];
        }
     }
   };
   
int main(){
   Queue q(10);
   q.push(10);
   q.push(15);
   q.push(20);
   q.push(25);
cout<<"Size of Queue:"<<q.getSize()<<endl;
q.pop();
cout<<"Size of Queue:"<<q.getSize()<<endl;
}