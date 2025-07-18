#include<iostream>
#include<stack>
using namespace std;
void insertbottom(stack<int>&st,int topelem){
    //base condition
    if(st.empty()||topelem<=st.top()){
        st.push(topelem);
        return;
    }
    int elem=st.top();
    st.pop();
    insertbottom(st,topelem);
    st.push(elem);
}
void sorted(stack<int>&st){
     //base condition
     if(st.empty()){
        return;
     }
     //one case
     int Topelem=st.top();
     st.pop();
     //function call
     sorted(st);
     insertbottom(st,Topelem);
}
int main(){
   stack<int>st;
   st.push(10);
   st.push(55);
   st.push(30);
   st.push(60);
   st.push(50);
   st.push(80);
  sorted(st);
 while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
 }
}