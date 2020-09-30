//
//  Backpacking01.cpp
//  PTA
//
//  Created by Alex on 2020/9/24.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "Backpacking01.hpp"
/*
 cw  表示当前已经装进去的物品的重量和；
 i 表示考察到哪个物品；
 w  表示背包cheng zhong；
 items  表示每个物品的重量；n表示物品个数
 假设背包可承受重量为100， 物品个数10， 物品重量储存在数组a中，那可以这样调用
 f(0, 0, a, 10, 100);
 
 **/
void Backpacking::f(int i, int cw, int *items, int n, int w){
    if(cw == w||i==n){
        //  已经装满,记录最佳结果
        if(cw > maxW)maxW = cw;
        return;
    }
    //回溯复原
    f(i+1,cw,items,n,w);
    if(cw + items[i]<=w){//超过承重后就不再装了
        f(i+1,cw+items[i],items,n,w);
    }
};
