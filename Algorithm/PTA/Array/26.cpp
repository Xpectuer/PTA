//
//  26.cpp
//  PTA
//
//  Created by Alex on 2020/10/21.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "26.hpp"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //双指针法
        if(!nums.size()){
            return 0;
        }
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i] != nums[j])
                i++;
            nums[i]=nums[j];
        }
        return i+1;
            
    }
};
