//
//  1.cpp
//  PTA
//
//  Created by Alex on 2020/10/1.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "1.hpp"


//swap
void swap(int &a,int& b){
        if(a == b)
            return;
        int temp;
        temp =a ;
        a =b;
        b = temp;

}
int* generateArray(int* array,int n,int mode){
    array=new int[n];
    
    if(mode==0){
    
        for(int i = 0 ; i < n ; i++){
                array[i]=0;
            }
        return array;
    
    }
    if(mode==1){
        
        for(int i = 0 ; i < n ; i++){
                array[i]=i;
        }
        return array;
        
    }
    return nullptr;
}

int* shuffleArray(int* array,int begin,int end){
    srand(time(NULL)); /*根据当前时间设置“随机数种子”*/

    if(!array){
        return NULL;
    }
    
    //shuffle
    if(begin>=end)
        return array;
    
    //这里swap在递归前会导致边界保持原状
    shuffleArray(array, begin+1, end);
    swap(array[begin], array[rand()%(end - begin)+begin]);

    
    //return array;
    return array;
}

int findGivenMax(int* arr,int range){
    int max =0;
    
    if(arr==nullptr){
        return -1;
    }
    
    for(int i = 0 ; i< range ; i++){
        if(arr[i]>max)
            max=arr[i];
    }
    
    return max;
}



//get permutation

//int** getPerm(int* list,int k , int n){
//
//    int ** result = nullptr;
//
//    if(k==0){
//        //n!
//        int n_stair=1;
//        //get n!
//        for(int i=n;i>=1;i--){
//            n_stair*=i;
//        }
//        //int ** result;
//        result=new int*[n_stair]{nullptr};
//        for(int i =0 ;i < n_stair;i++){
//            result[i] = new int[n];
//        }
//    }
//
//    if(k==n){
//
//        for(int i=0;i<n;i++){
//            result[m++][i]=list[i];
//        }
//        //return result;
//    }
//
//    else{
//        for(int i=k;i<=n;i++){
//            swap(list[i],list[k]);
//            getPerm(list, k+1, n);
//            swap(list[i],list[k]);
//
//
//
//        }
//
//    }
//
//
//
//
//    return result;
//
//}

// find the best wheat
// @param num_of_samples: the number of wheat to discard
std::vector<std::vector<double> > findPossibility(int num_of_samples,int time_of_test){
    // initialize the list
//    int num_of_samples ;
    
    int *array = nullptr;
    array = generateArray(array, num_of_samples,1);
    
    
    std::vector<std::vector<double> > rs;
    
    for(int i=0;i<num_of_samples;++i)
           rs.push_back(std::vector<double>());
    // vector<int>():创建一个空vector,调用了构造函数
       
       for(int i=0;i<num_of_samples;++i)
           for(int j=0;j<num_of_samples;++j)
               rs[i].push_back(0);

    
    //拒绝前k个
    for(int k = 1 ; k< num_of_samples ; k++){
        printf("Discard the first %d wheats...\n",k);
        // n 次实验
        for(int i=0; i < time_of_test;i++){
            
            array = shuffleArray(array, 0, num_of_samples);
            //样本组的最大值
            int max = findGivenMax(array, k);
            //实在没有比前面好的找最后一个
            
            int chosen_one;
            //寻找样本组中最大值
            chosen_one = array[num_of_samples];
                for(int i=k;i<num_of_samples;i++){
                    if(array[i]>max){
                        chosen_one = array[i];
                        break;
                    }
                }
           
            
            rs[k][chosen_one] += 1.0 / (double)time_of_test;
        }
    }
    
    return rs;

}
//提高样本域
//rate_of_sample+=0.01;

void printResult(){
    
    std::vector<std::vector<double> > v;
    int n;
    //int num_of_samples,int time_of_test
    std::ofstream outFile;
    outFile.open("/Users/alex/data/data.csv",std::ios::out);
    outFile << "sample"<<","<<"probability"<<std::endl;
    
    
    int n_boy =1000;
    int n_test=1000;
    
    v=findPossibility(n_boy,n_test);
    for(int i =1;i<n_boy;i++){
        printf("space of sample %d \n",i);
        //for(int j=0;j<100;j++){
          //  printf("%f ", v[i][j]);
           
        //}
        n = v[i].size()-1;
        
        printf("%f ",v[i][n]);
        printf("\n");
        outFile<<i<<","<<v[i][n]<<std::endl;

    }
    
    outFile.close();
    
    
}
