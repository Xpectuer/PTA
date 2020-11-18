//
//  1122.cpp
//  PTA
//
//  Created by Alex on 2020/11/14.
//  Copyright © 2020 Alex. All rights reserved.
//

#include <stdio.h>
# include <iostream>
#include<vector>

using namespace::std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int size = *max_element(arr1.begin(), arr1.end())+1;
        vector<int> counter(size);
        fill(counter.begin(), counter.end(),0);

         // count for each element

         cout << 1 <<endl;
         for(int num : arr1) {
             //cout << num <<endl;
             counter[num]++;
         }


       
         // scan for arr2
         int j = 0;
         cout << 1 <<endl;
         for(int x : arr2) {

                while(counter[x]) {
                    arr1[j++] = x;counter[x]--;
                }
            }
         

         // fill the rest
         cout << 1 <<endl;
         for(int i = 0 ;i < counter.size();i++ ) {
            cout << 2 <<endl;
             while(counter[i]--) {
                 arr1[j++] = i;

             }
         }

         return arr1;
         
    }
};

int main(){
    Solution so;
    vector<int> arr1={2,3,1,3,2,4,6,7,9,2,19}, arr2={2,1,4,3,9,6};
    so.relativeSortArray(arr1, arr2);
    
}
