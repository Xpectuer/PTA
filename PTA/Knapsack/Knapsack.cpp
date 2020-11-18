//
//  Knapsack.cpp
//  PTA
//
//  Created by Alex on 2020/10/27.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "Knapsack.hpp"

    
 /*Using Greedy*/
vector<int> knapsack(vector<Item> items, vector<Knap> knaps) {
        
        if(knaps.empty()||items.empty())return {};
        
        // result vector
        vector<int> rs(items.size());
        rs.clear();
        
        
        // priority queue Min-heap is applied to Knapsacks queue, Max-heap is applied to Item queue
        priority_queue<Item> item_q;
        priority_queue<Knap,vector<Knap>,greater<Knap>> knap_q;
        /*START of Initialization*/
        for(Item item:items) {
            item_q.push(item);
        }
        for(Knap knap:knaps) {
            knap_q.push(knap);
        }
        /*END of Initialization*/
        
        // decide which backpack to put
        while(!item_q.empty()) {
            // find the max cap
            Item item = item_q.top();
            // buffer the popded knaps
            vector<Knap> temp(knaps.size());
            // leave the capacity unchanged
            temp.clear();
            // proper condition to fill the item
            // Breadth First Search
            while(!knap_q.empty() && knap_q.top().remain < item.weight) {
                temp.push_back(knap_q.top());
                knap_q.pop();
            }
            
            Knap knap_proper = knap_q.top();
            // put into the knapsack
            if(!knap_q.empty()) {
                knap_proper.remain -= item.weight;
                rs.push_back(knap_proper.id);
            }
            else {
                rs.push_back(-1);
            }
            knap_q.pop();
            // dequeue
            item_q.pop();
            
            //restore the knap priority queue
            knap_q.push(knap_proper);
            for(Knap knap:temp) knap_q.push(knap);
            
            
        }
        
        return rs;
    }



/* Neighborhood Seaching From Greedy */

vector<int>  neighbourhood(vector<int> solution,vector<Item> items,vector<Knap> knaps) {
        if(items.size()!=solution.size())return {-1};
        //1. restore context from solution
        int i=0;
        for(int so:solution) {
            
            if(so==-1) continue;
            
            int weight = items[i].weight;
            knaps[so-1].remain-=weight;
            i++;
        }
        
       // for(Knap knap:knaps)
        //    printf("%d ",knap.remain);
        
        
        // get pq of unallocated items
        priority_queue<Item> item_pq;
    
        // initialize the unallocated item pq
        for(int i=0;i<solution.size();i++) {
            if(solution[i]==-1) {
                item_pq.push(items[i]);
            }
        }
    
        //2. get neighborhood
        // better solution to output
        vector<int> better_solution;
        int opt=0,
        curr=getValue(solution, items);
        neighbourHelper(0, solution, better_solution, knaps, items, item_pq, opt);
        //curr = opt;
        while(curr < opt) {
            curr = opt;
            neighbourHelper(0, better_solution, better_solution, knaps, items, item_pq, opt);
            
            printf("find solution: \n");
            for(int i:better_solution) printf("%d ",i);
            printf("\n");
        }
        // return result
        if(!better_solution.empty()) return better_solution;
        return {-1};
    }


// i index of knapsack
void neighbourHelper(int index_knap,
                     vector<int> &solution,
                     vector<int>  &better_solution,
                     vector<Knap> &knaps,
                     const vector<Item> items,
                     priority_queue<Item> &items_pq,
                     int& opt) {
        // solution
        // pop out
        // consider size
        if(index_knap == knaps.size()) return;
        
        //  value of current best solution to compare with the current one
        int curr_value= getValue(solution, items);
    
        // Which knapsack now?
        int id = knaps[index_knap].id;
    
        // get the Lowest Rating to pop and REMOVE the inferior one
        Item item = getInferiorItem(id,solution,items,knaps);
        
        
        if(item.value!=-1 && item.weight!=-1) items_pq.push(item);
        
        // get the top of pq
        item = items_pq.top();
    
        // choose a most rating item to reput
        if(isOk(index_knap, knaps,items_pq) ) {
            
            // insert the top item & try to put the rest item into the initial one
            updateSolution(index_knap, solution, knaps, items_pq);
            
            if( getValue(solution, items) > curr_value) {
                
                curr_value = getValue(solution, items);
                better_solution = solution;
                opt = curr_value;
            }
            
            return;
        }
        // recursion
        neighbourHelper(index_knap + 1, solution, better_solution, knaps, items, items_pq, opt);
        
    }

// The Item is ready to be  put into next knapsack
bool isOk(int knap_index, vector<Knap> knaps, priority_queue<Item> items_pq) {
    if(items_pq.empty()) return true;
    // find
    // size_t  size = knaps.size();
    // circular array
    return (knaps[knap_index].remain - items_pq.top().weight) >= 0;
}


int getValue(vector<int> solution, vector<Item> items) {
    int value=0;
    for(int i=0; i < solution.size(); i++) {
        if(solution[i]!=-1) value += items[i].value;
    }
    return value;
}

// Find the lowest rating in the current knapsack to pop
Item getInferiorItem(int id,vector<int> &solution,const vector<Item> items,vector<Knap> &knaps) {
    priority_queue<Item,vector<Item>,greater<Item>> pq;
    // scan for the knap
    for(int i=0; i<solution.size(); i++) {
        if(id == solution[i])
            pq.push(items[i]);
    }
    
    // represent empty
    if(pq.empty()) return Item(-1,-1,-1);
    
    // remove the inferior one
 
    int size = (int)knaps.size();
    
    rmFKnap( (id+size-1) % size, pq.top(), knaps, solution);
    
    return pq.top();
}

// insert the top item
void updateSolution(int index_knap, vector<int> &solution, vector<Knap> &knaps, priority_queue<Item> &items_pq) {
    Item item = items_pq.top();
    Knap knap =knaps[index_knap];
    items_pq.pop();
    
    add2Knap(index_knap, item, knaps, solution);
    
    // try to update the previous knap
    int prev = (index_knap + (int)knaps.size()-1) %  knaps.size();
    
    // tmp hold the unacceptable items
    vector<Item> trashbin;
    while(!items_pq.empty() ) {
        // put into the previous knap
            item = items_pq.top();
            items_pq.pop();
        if(item.weight > knap.remain) {
            trashbin.push_back(item);
        }
        else {
            add2Knap(prev, item, knaps, solution);
        }
    }
    // restore pq from tashbin
    for(Item it: trashbin) items_pq.push(it);
}

//To capsule the function that add knap and remove from knap
void add2Knap(int index_knap, Item item,vector<Knap> &knaps,vector<int> &solution) {
    
    Knap knap = knaps[index_knap];
    if(knap.remain - item.weight > 0) {
        knap.remain -= item.weight;
        knaps[index_knap] = knap;
        solution[item.id] = knap.id;
    }
}

void rmFKnap(int index_knap, Item item,vector<Knap> &knaps,vector<int> &solution) {
    Knap knap = knaps[index_knap];
    knap.remain += item.weight;
    knaps[index_knap] = knap;
    solution[item.id] = -1;
}
