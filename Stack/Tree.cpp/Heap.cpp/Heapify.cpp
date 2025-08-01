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
    void deletion(){
        if(size==0){
            cout<<" Heap is Empty"<<endl;
            return;
        } 
        arr[1]=arr[size];
        size--;
        //get correct position to the data
        int  i=1;
        while(i<size){
            int largest=i;//which data is set its correct place
            int leftChild=2*i;
            int rightChild=2*i+1;
            if(leftChild < size && arr[leftChild]>arr[largest]){
                swap(arr[largest],arr[leftChild]);
                largest=leftChild;
            }
             if(rightChild < size && arr[rightChild]>arr[largest]){
                swap(arr[largest],arr[rightChild]);
                largest=rightChild;
            }
            return;
        }
    }
    //for printig
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
 h.deletion();
 cout<<" After deletion Heap data  is"<<endl;
     h.print();
}