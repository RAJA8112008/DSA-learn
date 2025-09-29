#include<stdio.h>
#include<stdlib.h>
#define MAX 5
 int arr[MAX];
 int top=-1;
 //check stack is empty  or not
 int isempty(){
     return top==-1;
 }
 
 int isfull(){
     return top==MAX-1;
 }
 void  push(int data){
    //check stack is full or not
    if(isfull()){
      printf("Overflow");
    }
     top++;
    arr[top]=data;
 }
 //pop function 
 int pop(){
  if(isempty()){
    printf("Stack  is empty");
  }
  return arr[top--];
 }
 //to display the overall  stack
 int display(){
  if(isempty()){
    printf("Stack is empty");
  }
  for(int i=0;i<=top;i++){
       printf("%d",arr[i]);
  }
 }
 //check stack is full or not
int main(){
  push(10);
  push(20);
  push(30);
  push(40);
display();
}