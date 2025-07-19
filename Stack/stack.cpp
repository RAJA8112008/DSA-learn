#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
   vector<int>v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    stack<int>st;
    st.push(-1);
    vector<int>ans(v.size());
     for(int i= v.size()-1;i>=0;i--){
      int temp=v[i];
      while(temp<st.top()){
         st.pop();
      }
      ans[i]=st.top();
      st.push(temp);
     }
     for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
     }
     cout<<endl;
}