#include<iostream>
#include<stack>
using namespace std;


void midsearch(stack<int>&s,int &totalsize){
    
  //base conition
  if(s.size()==totalsize/2+1){
    cout<<"Middle elem is:"<<s.top()<<endl;
    return;
  }
int temp=s.top();
s.pop();
   midsearch(s,totalsize);
   s.push(temp);

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
   s.push(80);
  s.push(90);
  s.push(100);
int totalsize=s.size();
  midsearch(s,totalsize);
}
