//
//  EightQueen.cpp
//  PTA
//
//  Created by Alex on 2020/9/23.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "EightQueen.hpp"

    void  Solution::cal8queens(int row){//call cal8queen(0)
        if(row == 8){
            printQueen(result);
            printf("----------------\n");
            return;
        }
        for (int column=0; column< 8; column++) {
            if(isOk(row, column)){
                result[row] = column;
                cal8queens(row+1);
            }
        }
    }
   
    Solution::Solution(){
        this->result=new int[8];
    }

    bool Solution::isOk(int row,int column){
        int leftup = column - 1,rightup = column +1;
        for(int i = row -1 ;i>=0;--i){//逐行往上检查
            if(result[i]== column)return false;//第i行的column列是否有棋子
            if(leftup>=0){//考虑左上
                if(result[i]==leftup)return false;
            }
            if(rightup<=8){//考虑右上
                if(result[i]==rightup)return false;
            }
            --leftup;--rightup;
        }
        return true;
        
    }
    
    void Solution::printQueen(int* result){//打印
        for(int row=0;row<8;++row){
            for(int column=0;column<8;column++){
                if(result[row]==column)printf("Q ");
                else printf("* ");
            }
            printf("\n");
        }
        
        
    }
    

