#include<iostream>
using namespace std;
int main(){
    int arr[5]={12,5,7,58,0};
    for(int i=0;i<5;i++){ 
        for(int j=i+1;j<5;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    //Printing sorted array
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}