//
//  brace.cpp
//  PTA
//
//  Created by Alex on 2020/11/2.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "brace.hpp"

vector<string> Solution::generateParenthesis(int n) {
    
        if(n==0) return {};
    
        vector<string> rs;
        
        _generate(0,0,"",n,rs);
      
        return rs;
        
}

void Solution::_generate(int left, int right,string brace, int max,vector<string> &rs) {
        // 1. 先穷举所有情况 - good
        // 2. 迭代一次，判断合法性 -
        // 3. 再迭代，剪枝 -
    
        // terminate condition
    if(left ==max && right == max) {
            rs.push_back(brace);
            return;
    }
        
       

        // append string
    if(left < max)
        _generate(left+1,right, brace+="(", max, rs);
    if(left > right)
        _generate(left,right+1 , brace+=")", max, rs);
        
}


// X to be correct
//bool Solution::isOk(string str, int max) {
//    //if(str.length()==0) return false;
//    stack<char> stk;
//    for(char c:str) {
//        if(stk.size() > max) return false;
//        if(c=='(') stk.push(c);
//        else if(c==')') stk.pop();
//        //else return false;
//    }
//
//    return stk.empty();
//}
//
   
    
    
    


int main(){
    
    
    Solution so;
    
    vector<string> rs = so.generateParenthesis(3);
    
    for(string str:rs)
        cout<< str << endl;
    
    return 0;
}
