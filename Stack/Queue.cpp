#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void recursion(queue<int>&q){
    if(q.empty()){
        return;
    }
    int element=q.front();
     q.pop();
    //calling of the function
      recursion(q);
      q.push(element);
}

void reverseQueue(queue<int>&q){
  stack<int>st;
 while(!q.empty()){
   int element=q.front();
      q.pop();
      st.push(element);
 }
 while(!st.empty()){
  int element=st.top();
  st.pop();
  q.push(element);
 }
}
int main(){
  queue<int>q;
  q.push(3);
  q.push(5);
  q.push(4);
  q.push(9);
  q.push(7);
//   reverseQueue(q);
recursion(q);
  cout<<"Printing the Queue:"<<endl;
  while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
  }
  cout<<endl;
}