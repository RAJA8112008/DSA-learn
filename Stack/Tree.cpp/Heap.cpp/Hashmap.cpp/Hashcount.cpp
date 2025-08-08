#include<iostream>
#include<vector>
using namespace std;
 bool check(vector<int>& val){
    int n=val.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(val[i]>val[(i+1)%n]){
            count++;
        }
    }
    return count<=1;
 }
 
int main(){
  vector<int>val={3,4,5,1,2};
   if(check(val)){
      cout<<"YES"<<endl;
   }else{
    cout<<"NO"<<endl;
   }
}