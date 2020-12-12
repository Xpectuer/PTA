//
//  merge_sort.cpp
//  Algorithm
//
//  Created by Alex on 2020/12/11.
//

#include <stdio.h>
#include <vector>

using  namespace::std;

void merge(vector<int> &arr,int l,int mid,int r) {
    vector<int> tmp(r-l+1);
    int i = l, j = mid+1, k=0;
    // cmp & merge
    while(i<=mid&&j<=r) tmp[k++]=arr[i]<=arr[j]?arr[i++]:arr[j++];
    // pour
    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=r) tmp[k++] = arr[j++];
    // copy ***critical***
    for(int p = 0;p < tmp.size();p++) {
        arr[l+p] = tmp[p];
    }
    
}

void merge_sort(vector<int> &arr, int l, int r) {
   
    if(l>=r) return;
    int mid = l + ((r-l)>>1);
    
    merge_sort(arr, l, mid);
    merge_sort(arr, mid+1, r);
    merge(arr,l,mid,r);
    
}

int main() {
    vector<int> arr={5,234,12,2,312,122,21};
    //insert(arr,7);
    //select(arr, 7);
    //bubble(arr, 7);
    int n =arr.size()-1;
    //quickSort(arr, 0, n);
    merge_sort(arr, 0,  n);
    for(int i=0;i<7;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
