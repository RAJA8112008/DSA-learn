#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
  string str="Raja";
  unordered_map<char,int>map;
  for(int i=0;i<str.length();i++){
    char ch=str[i];
     map[ch]++;
  }
  //printing the final output
  for(auto i:map){
    cout<<i.first<<"->"<<i.second<<endl;
  }
}