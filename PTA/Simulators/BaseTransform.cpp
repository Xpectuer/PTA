//
//  BaseTransform.cpp
//  PTA
//
//  Created by Alex on 2020/9/30.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "BaseTransform.hpp"
// PAT B1022

int baseTrans(){
    //a,b: demical  d: base
    int a,b,d;
    int res[40],num=0;
    while(scanf("%d %d %d",&a,&b,&d)!=EOF){
        a= a +b;
        
        //base transformation
        do{
            
            res[num++] = a % d;
            a= a/d;
        }while(a!=0);
        
        for(int i=num-1;i>=0;){
            printf("%d",res[i--]);
        }
        printf("\n");
        
        
        
    }
   
    return 0;
    
    
    
}

