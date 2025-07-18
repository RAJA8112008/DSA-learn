#include<iostream>

using namespace std;
class stack{
  public:
  int *arr;
  int size;
  int top;
  stack(int size){
    arr=new int[size];
    this->size=size;
    top=-1;
  }
  void push(int data){
    if(size-top>1){
      top++;
      arr[top]=data;
    }else{
      cout<<"stack overflow"<<endl;
    }
  }
    void pop(){
      if(top==-1){
       cout<<"stack is underflow"<<endl;
      }else{
        top--;
      }
  }
  int getTop(){
    if(top==-1){
      cout<<"Empty"<<endl;
    }else{
      return arr[top];
    }
  }
  int getSize(){
    return top+1;
  }
  bool isEmpty(){
    if(top==-1){
      return true;
    }else{
      return false;
    }
  }
};
int main(){
    stack s(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    while(!s.isEmpty()){
      cout<<s.getTop()<<" ";
      s.pop();
    }
    return 0;
  }

  