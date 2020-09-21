//
//  B1001.cpp
//  PTA
//
//  Created by Alex on 2020/9/15.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "B1001.hpp"
int Callatz(int &n){
    
    if(n==1){
       return 0;
    }
    
    else if(n>1&&n<=1000){
        //even
        int step=1;
        while (1) {
            
        
            
        if(n%2==0){
            n=n>>1;
            
        }
        //odd
        else{
            n=(3*n+1)>>1;
        }
        
        if(n==1){
            return step;
        }
            step++;
        }
    }
    return 0;
    
}
