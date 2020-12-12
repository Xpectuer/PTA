//
//  codeup_100000575_A.cpp
//  PTA
//
//  Created by Alex on 2020/9/17.
//  Copyright © 2020 Alex. All rights reserved.
//

#include <stdio.h>
#include "codeup_100000575_A.h"

void solution(){
    int range[2];
    int m,n;
    bool isFirst;
    
    int L,M;
    
  
    
    while (1) {
        if(scanf("%d%d",&L,&M)==EOF||L>10000||L<1||M<1||M>100)
            break;
        
        isFirst=true;
        
        
    while(M--&&scanf("%d%d",&m,&n)!=EOF&&(m!=0||n!=0)){
        //boundary check
        
      
       if(m<0||n>L||n<0||n>L||m>n)
           break;
        
                
        if(isFirst||m<range[0]){
            range[0]=m;
            
            
        }
        if(isFirst||n>range[1]){
            range[1]=n;
            
        }
        if(isFirst)
            isFirst=false;
    
    }
    printf("%d\n",L-range[1]+range[0]);}
}
