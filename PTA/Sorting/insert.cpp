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
    for(int  i= 1;i<=n;i++){
        int temp = arr[i];
        int j=i;
        while (j > 0 && temp < arr[j-1]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}
