#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(5);
     st.push(6);
      st.push(7);
       st.push(7);
        st.push(8);

        //size of stack
        cout<<"Size of stack:"<<st.size()<<endl;
        //removing
        st.pop();
      cout<<"Size of stack:"<<st.size()<<endl;
}
