#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    //constructor
    Heap(){
      //start from index 1
      arr[0]= -1;
      size=0;
    }
    //inserting data in heap
    void insert(int data){
       size++;
       int index=size;
       arr[index]=data;
       //giving correct position to the data
       while(index>1){
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
        while(i<=size){
            int largest=i;//which data is set its correct place
            int leftChild=2*i;
            int rightChild=2*i+1;
            if(leftChild <= size && arr[leftChild]>arr[largest]){
                swap(arr[largest],arr[leftChild]);
                largest=leftChild;
            }
             if(rightChild <= size && arr[rightChild]>arr[largest]){
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
    // heapify
    void heapify(int arr[],int n,int i){
        int largest=i;
        int right=2*i+1;
        int left=2*i;
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,i);
        }
    }
};
int main(){
 Heap h;
 h.insert(55);
 h.insert(15);
 h.insert(59);
 h.insert(58);
 h.insert(122);
 cout<<"Heap data  is"<<endl;
 h.print();
 h.deletion();
 cout<<" After deletion Heap data  is"<<endl;
     h.print();
     int arr[6]={-1,55,53,62,58,73};
     int n=5;
     cout<<" Heapify  Heap data  is"<<endl;
     for(int i=n/2;i>0;i--){
       h.heapify(arr,n,i);
     }
     for(int i=1;i<=n;i++){
       cout<<arr[i]<<"  ";
     }cout<<endl;  
}