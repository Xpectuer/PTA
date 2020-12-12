//
//  Knapsack.hpp
//  PTA
//
//  Created by Alex on 2020/10/27.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef Knapsack_hpp
#define Knapsack_hpp

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
// item: the weight of each item
struct Item {
    // start from 0
    int id;
    // Weight Of the Item
    int weight;
    // Value Of the Item
    int value;
    Item(int id, int w,int v):weight(w),value(v),id(id){}
    Item(){}
    bool operator<(const Item &item) const{
            
        return (double)(value/weight) < (double)(item.value/item.weight);
    }
    bool operator>(const Item &item) const{
            
        return (double)(value/weight) > (double)(item.value/item.weight);
        }
};
struct Knap {
    // To identify which id use
    int id;
    // Capacity of knapsack
    int cap;
    // Remaining of knapsack
    int remain;
    Knap(int id, int  cap) :id(id),cap(cap),remain(0) {
        remain=cap;
    }
    Knap(){}
    bool operator>(const Knap &knap) const{
        return remain > knap.remain;
    }
    bool operator<(const Knap &knap) const{
        return remain < knap.remain;
    }
};
vector<int> knapsack(vector<Item> items, vector<Knap> knap );

vector<int>  neighbourhood(vector<int> solution,vector<Item> items,vector<Knap> knaps);
void neighbourHelper(int index_knap,
                     vector<int> &solution,
                     vector<int>  &better_solution,
                     vector<Knap> &knaps,
                     const vector<Item> items,
                     priority_queue<Item> &items_pq,
                     int &opt);

bool isOk(int i,vector<Knap> knaps,priority_queue<Item> items_pq);

int getValue(vector<int> solution, vector<Item> items);
Item getInferiorItem(int id,vector<int> &solution,const vector<Item> items,vector<Knap> &knaps);
void updateSolution(int index_knap, vector<int> &solution, vector<Knap> &knaps, priority_queue<Item> &items_pq);
void add2Knap(int index_knap, Item item,vector<Knap> &knaps,vector<int> &solution);
void rmFKnap(int index_knap, Item item,vector<Knap> &knaps,vector<int> &solution);
#endif /* Knapsack_hpp */
