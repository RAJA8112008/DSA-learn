#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    //constructor
    Heap(){
      //start from index 1
      arr[0]=-1;
      size=0;
    }
    //inserting data in heap
    void insert(int data){
       size++;
       int index=size;
       arr[index]=data;
       //giving correct position to the data
       while(size>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else{
            break;
        }
       }
    }
    void print(){
        for(int i=1;i<size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};
int main(){
 Heap h;
 h.insert(55);
 h.insert(15);
 h.insert(59);
 h.insert(58);
 h.insert(59);
 cout<<"Heap data  is"<<endl;
 h.print();
}