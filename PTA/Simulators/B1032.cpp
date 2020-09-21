//
//  B1032.cpp
//  PTA
//
//  Created by Alex on 2020/9/15.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "B1032.hpp"
#include <unordered_map>
void excavator(){
    //using unordered map
    int m,n,N;
    if(scanf("%d",&N)==0)
        return;
   // int record[n];
   
    std::unordered_map<int, int> map;
    //record
    
    while(N--&&scanf("%d%d",&m,&n)!=EOF){
        if(map.find(m)==map.end()){
            map[m]=n;
        }
        else if(map.find(m)!=map.end()){
            map[m]=map[m]+n;
        }
        else{
            break;
        }
        
        
    }
    //find the biggest
    std::unordered_map<int, int>::iterator it;
   // it=map.begin();
    int maxK=0,maxV=0;
    for(it=map.begin();it!=map.end();it++){
        if(it->second>maxV){
            maxV=it->second;
            maxK=it->first;
        }
        
    }
    printf("%d %d\n",maxK,maxV);
}
