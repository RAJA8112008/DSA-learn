#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s,int target){
  if(s.empty()){
    s.push(target);
    return;
  }
  int topEle=s.top();
  s.pop();
  //recursion call
  solve(s,target);
  //bt
  s.push(topEle);

}
 void bottomElem(stack<int>&s){
  if(s.empty()){
    cout<<"Not available"<<endl;
    return;
  }
  int target=s.top();
  s.pop();
  solve(s,target);
 }
int main(){
  stack<int>s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  s.push(60);
  s.push(70);

 bottomElem(s);

 while(!s.empty()){
  cout<<s.top()<<" ";
  s.pop();
 }cout<<endl;

}