//
//  EightQueen.hpp
//  PTA
//
//  Created by Alex on 2020/9/23.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef EightQueen_hpp
#define EightQueen_hpp

#include <stdio.h>
class Solution{
public:
    int* result;
    void cal8queens(int row);
    Solution();
    
private:
    bool isOk(int row,int column);
    
    void printQueen(int* result);
    
    
};
#endif /* EightQueen_hpp */
