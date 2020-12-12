//
//  ReducedBT.hpp
//  PTA
//
//  Created by Alex on 2020/10/14.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef ReducedBT_hpp
#define ReducedBT_hpp

#include <stdio.h>
#include <vector>
#include <stack>
/*
 1. i记录当前是那个物品
 2. rs记录当前和
 **/
#define SIZE 100

//输入的set默认已经从小到大排序完毕
using namespace::std;
//
//typedef struct myArray {
//    int* p;
//    int size;
//    myArray(int n):size(n){
//        p=new int[n];
//    }
//}myArray;


//class Subset{
//private:
//    int n;//集合大小
//    vector<int> set;
//    stack<int> decision; //记录当前的决策集合
//
//    int mid_rs; //记录中间结果
//    int target;
//    //计算目前深度剩下的和
//    int cal_rest_sum(vector<int> &set,int t){
//        this->set=vector<int>(set);
//        if(t>set.size()){
//            return INT_MIN;
//        }
//        int rs=0;
//        for(int i=t+1;i < set.size();i++){
//            rs+=set[i];
//        }
//        return rs;
//    }
//
//public:
//    vector<stack<int> > result;
//    Subset(vector<int> set,int target);
//
void back_tracking(int t,vector<int> set,int n, int mid_rs,int rest, int target, stack<int> decision,vector<stack<int>> &result);
    
    
//};
#endif /* ReducedBT_hpp */
