//
//  Counting.hpp
//  PTA
//
//  Created by Alex on 2020/10/26.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef Counting_hpp
#define Counting_hpp

#include <stdio.h>
#include <vector>


using namespace std;

void countingSort(vector<int> &nums);
int max(vector<int> &nums);
void getCount(vector<int> &nums,int* counter);
void accumulate(int* counter,int n);

#endif /* Counting_hpp */
