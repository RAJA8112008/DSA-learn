#include<stdio.h>
#include<stdlib.h>
  int fact(int num){
   //base condition
   if(num==0 ||num==1){
      return 1;
   }
   return (num)*fact(num-1);
  }
int main(){
   int num;
   printf("Enter the number");
   scanf("%d",&num);
   // fact(num);
   printf("%d",fact(num));
}