//
//  1.cpp
//  PTA
//
//  Created by Alex on 2020/10/22.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "1.hpp"
vector<int> twoSum(vector<int>& num, int target) {

     unsigned int i =0,j=num.size();
      
      if(j == 0) return {};
      
      int rs =0;
      sort(num.begin(),num.end());
      vector<int> result; 
      while(i<j) {
          rs = num[i]+num[j];
          if(rs  < target) i++;
          if(rs  > target) j--;
          else{
              result.push_back(num[i]);
              result.push_back(num[j]);
          }
          // while( i<j && num[i]==num[i+1])i++;
          // while( i<j && num[j]==num[j-1])j--;
          
      }
      // acceleration
      
      return result;
  }
