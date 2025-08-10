#include<stdio.h>
int main(){
      int a[4][5] = {
        {1, 1, 1, 1, 1}, // Employee 0
        {1, 0, 1, 1, 1}, // Employee 1
        {0, 0, 1, 1, 0}, // Employee 2
        {1, 1, 1, 1, 1}  // Employee 3
    };
   char *dayName[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
     // Total attendance per employee

    printf("Total attendance per employee");
    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0;j<5;j++){
            sum+=a[i][j];
            printf("%d ",sum);
        }
    }


}