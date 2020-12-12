//
//  codeup1934.cpp
//  PTA
//
//  Created by Alex on 2020/9/18.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "codeup1934.hpp"
void sequential(){
    int n,t;
    int arr[210];
    while(1){
    if(scanf("%d",&n)==EOF)
        break;;
    if(n<0||n>200)
        break;
    
    
    
    for(int i=0;i<n;++i){
        if(scanf("%d",&arr[i])==EOF)
            break;
    }
    scanf("%d",&t);
    
        int i;
        
        for(i=0;i<n;++i){
            if(arr[i]==t){
                printf("%d\n",i);
                break;
            }
        }
       if(i==n){
                  printf("-1\n");
              }
        
    }
    
    
    
}
