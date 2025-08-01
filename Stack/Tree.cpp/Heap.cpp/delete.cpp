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
        while(i<=size){
            int leftchild=2*i;
            int rightchild=2*i+1;
            int largest=i;
            if(leftchild<size && arr[leftchild]>arr[largest]){
                swap(arr[leftchild],arr[largest]);
                largest=leftchild;
            }
            if(rightchild<size && arr[rightchild]>arr[largest]){
                swap(arr[rightchild],arr[largest]);
                largest=rightchild;
            }
            break;
        }
        
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
      
      cout << "After Deletion:" << endl;
    h.deletion();  
    h.print();
}