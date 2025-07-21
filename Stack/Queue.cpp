#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseK(queue<int>&q,int k){
  stack<int>st;
  int count=0;
  int n=q.size();
   if(k==0 ||k>n){
    return;
   }
   while(!q.empty()){
    int element=q.front();
    q.pop();
    st.push(element);
    count++;
    if(count==k){ 
      break;
    }
   }
   //stack to queue
      while(!st.empty()){
      int element=st.top();
      st.pop();
      q.push(element);
    }
    // again enter in queue remaining elements
    count=0;
    while(!q.empty()){
      int element=q.front();
      q.pop();
      q.push(element);
      count++;
      if(count==n-k){
        return;
      }
    }
}
int main(){
queue<int>q;
q.push(4);
q.push(5);
q.push(8);
q.push(6);
q.push(1);
reverseK(q,3);
cout<<"Printing the queue"<<endl;
while(!q.empty()){
  cout<<q.front()<<" ";
  q.pop();
}
cout<<endl;
}