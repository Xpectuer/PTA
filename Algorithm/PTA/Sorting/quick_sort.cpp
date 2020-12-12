//
//  quick_sort.cpp
//  Algorithm
//
//  Created by Alex on 2020/12/11.
//

#include <stdio.h>
#include <vector>
#include <random>
using namespace std;

int partition(vector<int> &arr, int begin, int end) {
    // find the pivot
    // it is better to use random algo to select a pivot
    // pivot: position of pivot , counter: num of element smaller than element pivot
    
    //int pivot = rand() % (end - begin+1) + begin;  //随机选择pivot ！！！有问题回来优化
    int pivot = end;
    int counter = begin;
    
    for(int i=begin;i<=end;i++) {
        if(arr[i] < arr[pivot]) {
            swap(arr[i],arr[counter]);
            counter++;
        }
       
    }
    swap(arr[pivot],arr[counter]);
    // ...
    return counter;
}

void quickSort(vector<int> &arr,int begin,int end) {
    if(begin>=end) return;
    int pivot = partition(arr,begin,end);
    quickSort(arr,begin,pivot-1);
    quickSort(arr,pivot+1,end);
}

int main() {
    vector<int> arr={5,234,12,2,312,122,21};
    //insert(arr,7);
    //select(arr, 7);
    //bubble(arr, 7);
    int n =arr.size()-1;
    quickSort(arr, 0, n);
    for(int i=0;i<7;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}


