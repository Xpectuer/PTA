//
//  Obama.cpp
//  PTA
//
//  Created by Alex on 2020/9/29.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "Obama.hpp"

int printSquare(){
    int n,w;
       char s;
    if(scanf("%d %c",&n,&s)==EOF)
        return -1;
   
    if(n%2==0)
        w = n>>1;
    else
        w = (n+1)>>1;
    
       for(int i=0;i<w;i++){
           
           if(i==0||i==w-1){
               for(int j=0;j<n;j++){
                   printf("%c",s);
               }
           }
           else{
               printf("%c",s);
               for (int k=0; k<n-2; k++) {
                   printf(" ");
               }
               printf("%c",s);
           }
           printf("\n");
       }
       
       
       return 0;
}
