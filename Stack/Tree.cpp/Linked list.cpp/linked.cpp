#include<stdio.h>
#include<stdlib.h>
  int main(){
   int num;
   long  long fact=1;
   printf("Enter the numbers:");
   scanf("%d",&num);
   for(int i=1;i<=num;i++){
   fact=fact*i;
   }
   printf("%d",fact);

  }