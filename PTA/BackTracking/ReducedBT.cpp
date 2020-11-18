//
//  ReducedBT.cpp
//  PTA
//
//  Created by Alex on 2020/10/14.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "ReducedBT.hpp"

//t depth
void back_tracking(int t,vector<int> set,int n, int mid_rs,int rest, int target, stack<int> decision,vector<stack<int>> &result){
    // 到达叶子节点
    if(t>=n){
        printf("\n result: %lu \n",result.size());
        printf("\n mid_rs: %d \n",mid_rs);
        if( mid_rs == target ){
            //记录一个符合条件的
            result.push_back(decision);
            }
        }
    
   
    // 找到一个组合
    // t!=0 防止 target=0 直接返回
    
    
  
    // 搜索右子树 0
    // 剪枝
    else{

        // 搜索左子树 1
        if(mid_rs+set[t] <=target){
            printf("到达左！\n");
            printf("rest: %d",rest);
         //  printf("cal: %d\n", rest, t));
            decision.push(1);
           // printf("%d ",decision.top());
            back_tracking(t+1,set,n,mid_rs+set[t],rest-set[t],target,decision,result);
            // 回溯复原
            decision.pop();
           
            
        }
        
        if( mid_rs+ rest -set[t] >= target ){
            printf("到达右！\n");
           // printf("cal: %d\n", rest, t));
            decision.push(0);
            printf("%d ",decision.top());
            back_tracking(t+1,set,n,mid_rs,rest-set[t],target,decision,result);
            decision.pop();

        }
      

    }
 
    // 回溯
 
}

//
//Subset(vector<int> set,int target){
//
//    n=(int)set.size();
//    target = target;
//    mid_rs=0;
//    set=set;
//}


