//
//  Counting.cpp
//  PTA
//
//  Created by Alex on 2020/10/26.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "Counting.hpp"

void countingSort(vector<int>& nums) {
    
    // find the max value
    // initialize the counter
    if(nums.size()==0)
        return;
    
    int n = max(nums)+1;
    int* counter = new  int[n]{0};

    //count
   getCount(nums,counter);
    //accumulate the counter
   accumulate( counter,n);
   
    vector<int> sorted=vector<int>(nums.size());
    
    for(int i= nums.size() - 1; i>=0; i--) {
        
        int index = counter[nums[i]] - 1;
        sorted[index]=nums[i];
        counter[nums[i]]--;

    }
    
    nums=vector<int>(sorted);
    
}
int max(vector<int> &nums) {
    int max =INT_MIN;
    
    for(int n:nums) {
        max  = n>max?n:max;
    }
    
    return max;
}

void getCount(vector<int> &nums,int* counter) {
    
    for(int n :nums) {
        counter[n] ++;
    }
        
}

void accumulate(int* counter,int n) {
    for(int i=1;i < n;i++) {
        counter[i]+=counter[i-1];
    }
}
