//
//  1.hpp
//  PTA
//
//  Created by Alex on 2020/10/1.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef __hpp
#define __hpp

#include <stdio.h>
#include <cmath>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
// to testify the Wheat Problem
int* generateArray(int* array,int n,int mode);

void swap(int& a , int& b);
int* shuffleArray(int* array,int begin, int end);

//int ** getPerm(int* list,int k ,int n);
int findGivenMax(int* arr,int range);

double findPossibility();

void printResult();

#endif /* __hpp */
