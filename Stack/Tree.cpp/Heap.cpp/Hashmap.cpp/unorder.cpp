#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    //insertion in map
    pair<string,int>p=make_pair("Rahul",8);
    m.insert(p);
    pair<string,int>p2=make_pair("Kumar",5);
    m["Saniya"]=5;
    //asses
   cout<< m.at("Rahul")<<endl;
   cout<<m["Saniya"]<<endl;
}