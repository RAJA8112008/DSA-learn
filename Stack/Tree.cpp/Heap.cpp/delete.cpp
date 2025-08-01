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
    //Deletion of data in heap
    void deletion(){
        if(size==0){
        cout<<"Nothing to  Delete"<<endl;
        return;
        }
        arr[1]=arr[size];
        size--;
        //take root node to  its correct position
        int i=1;
        while(i<size){
            int leftchild=2*i;
            int rightchild=2*i+1;
            if(leftchild<size && arr[leftchild]>arr[i]){
                swap(arr[leftchild],arr[i]);
                i=leftchild;
            }
            if(rightchild<size && arr[rightchild]>arr[i]){
                swap(arr[rightchild],arr[i]);
                i=rightchild;
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
      cout<<"Deletion of data"<<endl;
      h.print();
}