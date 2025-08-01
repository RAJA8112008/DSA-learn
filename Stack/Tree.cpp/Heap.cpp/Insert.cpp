#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int data){
       size++;;
      int index=size;
      arr[index]=data;
     
      while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }else{
            return;
        }
      }
    }
    void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
   }
} ;
int main(){
 Heap h;
 h.insert(55);
 h.insert(56);
 h.insert(95);
 h.insert(58);
 h.insert(53);
 h.insert(51);
 cout<<"Print the Heap:"<<endl;
 h.print();
}