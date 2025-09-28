#include<stdio.h>
#include<stdlib.h>
int tailRecursion(int num,int result){
    if(num==0 ||num==1){
      return result;
    }
    return tailRecursion(num-1,num*result);

}
  int main(){
   //tail recursion
  int num;
  int result=1;
  printf("Enter the num:");
  scanf("%d",&num);
  result= tailRecursion(num,result);
   printf("%d",result);
  }