//
//  longpressed.cpp
//  PTA
//
//  Created by Alex on 2020/10/21.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "longpressed.hpp"
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.size()<name.size())
            return false;
        int i=0,j=0;
        
        while(i<name.size()){
            if(name[i]!=typed[j])
                return false;
            i++;
            j++;
            
            // skip the long pressed part in name
            if(i<name.size() && name[i]!=name[i-1]){
                while(typed[j]==typed[j-1])
                    j++;
            }
        }
        
        // skip the long pressed part
        while(j<typed.size() && typed[j]==typed[j-1])
            j++;
        // if j hasn't travsed the typed
        if(j!=typed.size())
            return false;
        return true;
    }
};
