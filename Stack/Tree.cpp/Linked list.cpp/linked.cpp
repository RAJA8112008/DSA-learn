#include<stdio.h>
#include<stdlib.h>
int sumofDigit(int num){
   //base case
   if(num==0){
      return 0;
   }
   return (num%10)+sumofDigit(num/10);
}

int main(){
   int num;
   printf("Enter the number:");
   scanf("%d",&num);
   
   printf("Sum of digits: %d",sumofDigit(num));
}