//
//  brace.hpp
//  PTA
//
//  Created by Alex on 2020/11/2.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef brace_hpp
#define brace_hpp

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
private:
    void _generate(int left, int right, string brace, int max,vector<string> &rs);
    // To judge if the parenthesis in string is valid
    bool isOk(string str, int max);
public:
    vector<string> generateParenthesis(int n) ;
        
    
};


#endif /* brace_hpp */
