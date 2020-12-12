//
//  main.cpp
//  PTA
//
//  Created by Alex on 2020/9/15.
//  Copyright © 2020 Alex. All rights reserved.
//



#include <stdio.h>
#include "Knapsack.hpp"



//
//
//struct LinkedNode {
//    int val;
//    LinkedNode *next;
//
//
//    LinkedNode(int val){
//        this->val = val;
//        next = nullptr;
//
//    }
//};
//
//class MyCircularDeque {
//private:
//    LinkedNode* head,*rear;
//    int size,capacity;
//
//public:
//    /** Initialize your data structure here. Set the size of the deque to be k. */
//
//    MyCircularDeque(int k) {
//
//        head = nullptr;
//        rear = nullptr;
//        size = 0;
//        capacity = k;
//    }
//
//    /** Adds an item at the front of Deque. Return true if the operation is successful. */
//    bool insertFront(int value) {
//
//        if(!isFull()) {
//
//                LinkedNode* newnode = new LinkedNode(value),
//                *temp = head;
//
//
//                if(isEmpty()) {
//                    head = newnode;
//                    rear = newnode;
//                }
//
//
//                head = newnode;
//                if(temp) newnode ->next = temp;
//                rear -> next = head;
//
//                size++;
//
//                return true;
//        }
//
//        return false;
//    }
//
//    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
//    bool insertLast(int value) {
//              if(!isFull()) {
//
//                LinkedNode* newnode =new LinkedNode(value),
//                *temp = rear;
//
//                if(isEmpty()) {
//                    head = newnode;
//                    rear = newnode;
//
//                }
//
//                rear = newnode;
//                if(temp) temp->next = rear;
//                rear->next = head ;
//
//
//                size++;
//                return true;
//
//        }
//
//        return false;
//    }
//
//    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
//    bool deleteFront() {
//             if(!isEmpty()) {
//
//                 if(rear == head) {
//                    rear = nullptr;
//                    head = nullptr;
//                     size--;
//                     return true;
//                 }
//
//                 head = head -> next;
//                 rear -> next = head;
//                 size--;
//                 return true;
//
//        }
//        return  false;
//    }
//
//    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
//    bool deleteLast() {
//
//           if(!isEmpty()) {
//
//            LinkedNode* temp = head;
//           // maintain_rear(rear);
//               if(rear == head) {
//                  rear = nullptr;
//                  head = nullptr;
//                   size--;
//                   return true;
//               }
//
//           while(temp->next != rear) {
//               temp = temp->next;
//           }
//
//            //kill
//            temp ->next = head;
//            rear = temp;
//
//            size--;
//            return true;
//
//        }
//        return  false;
//
//    }
//
//    /** Get the front item from the deque. */
//    int getFront() {
//        return isEmpty()?-1:head->val;
//    }
//
//    /** Get the last item from the deque. */
//    int getRear() {
//        return isEmpty()?-1:rear->val;
//    }
//
//    /** Checks whether the circular deque is empty or not. */
//    bool isEmpty() {
//        return  size == 0;
//    }
//
//    /** Checks whether the circular deque is full or not. */
//    bool isFull() {
//        return  size == capacity ;
//
//    }
//
//};


int main(int argc, const char * argv[]) {
     //insert code here...
    //int n;
//    Solution* so=new Solution();
//    so->cal8queens(0);
//    return 0;
    //getchar();
   // printSquare();
    //baseTrans();
//    int* arr = nullptr;
//    arr=generateArray(arr,100,1);
//    arr = shuffleArray(arr, 0, 100);
//    for(int i =0 ;i<100;++i)
//        printf("%d ",arr[i]);
    
//    int n=10,m=2;
//
//    //char* 初始化在C++中必须强制类型转换
//    char* a = (char*)"aaaaaaaaab";
//    char* b = (char*)"ab";
//
//
//    int i = bm1(a,n,b,m);// expect:
//
//    printf("%d\n",i);
//    return 0;
//
//    std::vector<int> items ={-5,-4,-2,1,2,4,5} ,track;
//
//    std::vector<std::vector<int> > selections;
//
//    int n = (int)items.size();
//    printf("%d\n",n);
//    back_tracking(0, 0, items, n, 5, track, selections);
//
//    for(auto a: selections){
//        for(auto k:a){
//            printf("%d ",k);
//        }
//
//        printf("\n");
//    }
//    return 0;
 
//    stack<int> decision;
//    vector<stack<int> > result;
//    vector<int> set ={-2,-3,4,5};
//
    //为了正向显示
//    stack<int> r;
//    int n= int(set.size());
//    int rest=0;
//    int target =0;
//    for(auto it=set.begin();it!=set.end();it++){
//       // printf("%d\n",*it);
//        rest+=*it;
//    }
  //  Subset sbst(set,0);
//    back_tracking(0,set,n,0,rest,target,decision,result);
//
//    vector<stack<int> >::iterator it;
//
//    printf("\n result size:%lu \n",result.size());
//    for(it = result.begin() ; it!=result.end() ; ++it){
//
//        while(!(*it).empty()){
//           // printf("%d ",(*it).top());
//            r.push((*it).top());
//            (*it).pop();
//        }
//        while(!r.empty()){
//            printf("%d ",r.top());
//            //r.push((*it).top());
//            r.pop();
//        }
//        printf("\n");
//    }

//    int* a =new int[10]{5,4,2,3,5,6,12,1,7,2};
//    int n = 10;
//    insert(a, n);
//
//    for(int i=0;i<n;i++){
//        printf("%d ",a[i]);
//    }
//    printf("\n");
//    return 0;
//string name="kikcxmvzi";
//
//string type="kiikcxxmmvvzz";
//
//
//printf("%d\n ", isLongPressedName(name, type));
    
//
//    vector<int> array ={2,7,11,15};
//    int target = 9;
//
//    twoSum(array, target);
//    printf("good\n");
//    MyCircularDeque so(8);
//    so.insertFront(5);//1
//    printf("%d\n",so.getFront());
//    so.isEmpty();
//    so.deleteFront();//0
//    so.insertLast(1);//1
//    printf("%d\n",so.getRear());
//    so.insertLast(2);//2
//    so.insertFront(3);//3
//    so.deleteLast();//2
//    so.insertLast(5);
//    so.isEmpty();
    
//    vector<int> a= {2,3,2,1,6,7,6,2,14};
//    countingSort(a);
//
//    for(int i:a){
//        printf("%d ",i);
//    }
//
//    printf("\n");
    
   // priority_queue<Item> pq;
   //id  weight value
    Item item1(0,2,11);
    Item item2(1,5,2);
    Item item3(2,7,10);
    Item item4(3,6,20);
    Item item5(4,7,7);
    Item item6(5,9,12);
    Item item7(6,1,20);
    Item item8(7,5,50);
    vector<Item> items = {item1,item2,item3,item4,item5,item6,item7,item8};
//    for(Item item:items) pq.push(item);
//    while(!pq.empty()) {
//
//
//
//        printf("%f ",(double)pq.top().value/pq.top().weight);
//        pq.pop();
//    }
    
    printf("\n");
    // less 大顶堆 greater 小顶堆
    priority_queue<Knap,vector<Knap>,greater<Knap>> kpq;
    //        id , capacity
    Knap knap1(1,8);
    Knap knap2(2,6);
    Knap knap3(3,4);
    Knap knap4(4,10);
    Knap knap5(5,4);
    Knap knap6(6,20);
    vector<Knap> knaps = {knap1,knap2,knap3,knap4,knap5,knap6};
    
//    for(Knap knap:knaps) kpq.push(knap);
//    while(kpq.size()!=1) {
//        printf("%d ",kpq.top().id);
//        kpq.pop();
//    }
//    printf("%d ",kpq.top().id);
//
//    printf("\n");
//
//    vector<int> temp(10);
//    temp.clear();
//    temp.push_back(1);
//    for(int i:temp) printf("%d ",i);
//
    
    
    vector<int> rs = knapsack(items, knaps);
    
    printf("Initial Solution: \n");
    for(int i:rs) printf("%d ",i);
    
    printf("\n");
    printf("Value: %d\n",getValue(rs, items));

    vector<int> rs_b = neighbourhood(rs, items, knaps);




    printf("Better Solution：\n");
    for(int i:rs_b) printf("%d ",i);
    printf("\n");
    printf("Value: %d\n",getValue(rs_b, items));
    printf("\n");
    
    /*----------------------------------------*/
    
//    priority_queue<int,vector<int>> pq ;//={1,3,4,1,2,4,5}
//    pq.push(1);
//    pq.push(2);
//    while(!pq.empty()) {
//        printf("%d ",pq.top());
//        pq.pop();
//    }
        return 0;
}
