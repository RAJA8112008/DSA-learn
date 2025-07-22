#include<iostream>
#include<queue>
using namespace std;
int  main(){
  string str="aabc";
  int freq[26]={0};
  string ans="";
  queue<char>q;
 for(int i=0;i<str.length();i++){
  char ch=str[i];
  freq[ch-'a']++;
  
  q.push(ch);
 }
 while(!q.empty()){
    if(freq[ch-'a']>1){
       q.pop();
    }else{
      
    }
 }

}