#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    //Constructor
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int data){
        size++;
        int index=size;
        arr[index]=data;
      while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
             index=parent;
        }
       
      }
      return;
    }
    //printing process
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
int main(){
 Heap h;
    h.insert(5);
    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(45);
    h.insert(55);
    cout<<"Heap data  is :"<<endl;
      h.print();
}