//
//  Backpacking01.hpp
//  PTA
//
//  Created by Alex on 2020/9/24.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef Backpacking01_hpp
#define Backpacking01_hpp

#include <stdio.h>
#include <cmath>
class Backpacking{
public:
    //背包承重
    int maxW = INT32_MIN;
    /*
     cw表示当前已经装进去的物品的重量和；
     i表示考察到哪个物品；
     w表示背包重量；
     items表示每个物品的重量；n表示物品个数
     假设背包可承受重量为100， 物品个数10， 物品重量储存在数组a中，那可以这样调用
     f(0, 0, a, 10, 100);
     
     **/
    void f(int i,int cw,int* items,int n,int w);
    
};
#endif /* Backpacking01_hpp */
