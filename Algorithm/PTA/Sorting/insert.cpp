//
//  insert.cpp
//  PTA
//
//  Created by Alex on 2020/10/17.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "insert.hpp"
 
void insert(int* arr, int n){
    //无序部分向有序部分插入
    // i 指向有序
    for(int  i= 1;i<n;i++){
        int temp = arr[i];
        int j=i;
        while (j > 0 && temp < arr[j-1]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

void select(int* arr,int n) {
    int j = 0, i=0;
    int min_index = 0;
    for(i=0;i<n;i++) {
        min_index = i;
        for(j=i;j<n;j++) {
            if(arr[j]<arr[min_index]) min_index = j;
        }
        // swap
        int temp = arr[i];arr[i] = arr[min_index];arr[min_index] =temp;
    }
}

void bubble(int *arr, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];arr[j+1] = arr[j];arr[j] =temp;
            }
        }
    }
}



int main() {
    int * arr =new int[7]{5,234,12,2,12,12,21};
    //insert(arr,7);
    //select(arr, 7);
    bubble(arr, 7);
    for(int i=0;i<7;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
