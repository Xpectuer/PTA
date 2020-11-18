//
//  EightQueen.cpp
//  PTA
//
//  Created by Alex on 2020/9/23.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "EightQueen.hpp"

    void  Solution::cal8queens(int row){//call cal8queen(0)
        // 停止条件：到达棋盘最后一行
        // 打印一种解法
        if(row == 8){
            printQueen(result);
            printf("----------------\n");
            return;
        }
        
        // 遍历每一列
        for (int column=0; column< 8; column++) {
            //判断是否合理
            if(isOk(row, column)){
                //记录一种解法
                result[row] = column;
                //遍历下一行
                cal8queens(row+1);
            }
        }
    }
   
    Solution::Solution(){
        this->result=new int[8];
    }

    // 判断 该行该列 是否符合条件
    // 即 是否存在皇后攻击范围内的棋子
    bool Solution::isOk(int row,int column){
        int leftup = column - 1,rightup = column +1;
        
        //逐行往上检查
        for(int i = row -1 ;i>=0;--i){
            
            //第i行的column列（本列）是否有棋子
            if(result[i]== column)return false;
            
            //考虑左上
            if(leftup>=0){
                if(result[i]==leftup)return false;
            }
            
            //考虑右上
            if(rightup<=8){
                if(result[i]==rightup)return false;
            }
            --leftup;++rightup;
        }
        return true;
        
    }
    
    void Solution::printQueen(int* result){//打印
        for(int row=0;row<8;++row){
            for(int column=0; column<8; column++){
                if(result[row] == column)printf("Q ");
                else printf("* ");
            }
            printf("\n");
        }
        
        
    }
    

