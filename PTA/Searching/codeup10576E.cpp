//
//  codeup10576E.cpp
//  PTA
//
//  Created by Alex on 2020/9/18.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "codeup10576E.hpp"
struct Student {
    int id,age;
    char name[20],gender[20];
}s[20];

int solution(){
    int M,N,target;
    scanf("%d",&M);
    while(M--){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d %s %s %d",&s[i].id,s[i].name,s[i].gender,&s[i].age);
        }
        
        scanf("%d",&target);
        
        for(int i=0;i<N;i++){
            if(target==s[i].id){
                printf("%d %s %s %d\n",s[i].id,s[i].name,s[i].gender,s[i].age);
                break;
            }
        }
        
    }
    
    
    return 0;
}
