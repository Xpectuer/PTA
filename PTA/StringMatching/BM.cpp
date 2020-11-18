//
//  BM.cpp
//  PTA
//
//  Created by Alex on 2020/10/8.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "BM.hpp"

#define SIZE 256


/*
    @param b pattern str
           m length of pattern str
           bc hash table
 */
void generateBC(char* b, int m,int * bc){
    
    for(int i = 0; i<SIZE;i++ ){
        bc[i] = -1; //initiate bc
    }
    //generate bc
    for (int i = 0; i < m; i++) {
        int ascii = (int)b[i] ; //计算b[i] 的ASCII值
        bc[ascii] = i ;
    }
}



/*
 
    @param main main string
           pattern pattern string
           n num of main string
           m length of pattern string
    
 */
// 不考虑负位移的情况（仅仅是坏字符规则）
// BC : Bad Character
int bm(char* main, int n, char* pattern, int m){
    //记录模式串中最后出现的位置
    int* bc =new int[SIZE];
    
    generateBC(pattern, m, bc);
    
    // i表示主串与模式串对齐的第一个字符
    int i = 0;
    while(i <= n - m){
        int j;
        
        // matching
        for(j= m-1; j>=0;j--){ // 模式串从后往前匹配
            if(main[i+j] != pattern[j])
                break;
        }
        
        if(j < 0){
            return i; //match done !
        //向后滑动 j - bc[(int)main[i+j]]  (si - xi)位
        }
        
        i = i + (j - bc[(int)main[i+j]]);
        
        
    }
    
    return  -1;
}

int max(int x,int y){
    return x>y?x:y;
}



void generateGS(char* pattern,int m, int* suffix, bool * prefix){
    for(int i = 0;i < m; i++){
        suffix[i] = -1;
        prefix[i] = false;
        
    }
    
    for(int i=0; i< m - 1; ++i){ // b[0 ,i]
        
        // i是前缀，也就是在模式串前缀中匹配后缀子串
        int j = i;
        
        // 公共后缀子串长度
        int k = 0;
        // 匹配公共后缀子串
        // 倒着匹配
        while(j>=0 && pattern[j] == pattern[m-1-k]){ // 与 pattern[0, m-1]求公共后缀子串
            --j;
            ++k;
            suffix[k] = j+1;// j+1表示公共后缀子串在 pattern 中的起始下标
        }
        
        if(j==-1)
            prefix[k]=true;
    }
}

// j 坏字符下标 m表示模式串长度
int moveByGS(int j,int m,int* suffix,bool* prefix){
    int k = m -1 -j;// 好后缀的长度
    if(suffix[k] != -1)
        return j - suffix[k] + 1;
    for(int r =j+2; r<=m-1; r++){
        // 好后缀子串的匹配前缀
        if(prefix[m - r])
            return r;
    }
    return m;
    
}



// 填充好后缀原则
int bm1(char* main, int n, char* pattern, int m){
    //记录模式串中最后出现的位置
    int* bc =new int[SIZE];
    
    generateBC(pattern, m, bc);
    
    int* suffix =new int[m];
    bool* prefix = new bool[m];
    
    generateGS(pattern, m, suffix, prefix);
    // i表示主串与模式串对齐的第一个字符
    int i = 0;
    while(i <= n - m){
        int j;
        
        // matching
        for(j= m-1; j >= 0; j--){ // 模式串从后往前匹配
            if(main[i+j] != pattern[j])
                break;
        }
        
        if(j < 0){
            return i; //match done !
        // 向后滑动 j - bc[(int)main[i+j]]  (si - xi) 位
        }
        
        
        
        int x =   j - bc[(int)main[i+j]] ;
        int y = 0;
        //如果有坏字符  且可能有好后缀
        if(j < m-1){
            y = moveByGS(j, m, suffix, prefix);
        }
        i = i+ max(x,y);
    }
    return  -1;
}









