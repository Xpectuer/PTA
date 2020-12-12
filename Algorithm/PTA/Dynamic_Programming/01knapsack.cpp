//
//  01knapsack.cpp
//  Algorithm
//
//  Created by Alex on 2020/12/11.
//

#include<stdio.h>
#include<vector>
using namespace std;

// input 2 array
//       cap of knap
// output int biggest value
int maxValue(const vector<int> weights, const vector<int> values, int cap) {
    if(weights.size()==0||values.size()==0) return 0;
    size_t m = weights.size();
    
    vector<vector<int> > dp(m,vector<int>(cap+1,-1));
    
    
    if(weights[0]<=cap) {
        // first item trial
        dp[0][weights[0]] = values[0];
    }
    // i: num of knap, j: weight of current
    for(int i=1;i<m;i++) {
        
        for(int j=0;j<=cap;j++) {
            // not put i item
            if(dp[i-1][j] >= 0) dp[i][j] = dp[i-1][j];
        }
        // only pick up in current_weight + weight[i]
        for(int j=1;j<=cap-weights[i];j++) {
            if(dp[i-1][j] >=0) {
                
                int v = dp[i-1][j] + values[i];
                
                if(v > dp[i][j+weights[i]])
                    // put the i item
                    dp[i][j+weights[i]] = v;
                }
            }
    }
    int max = -1;
    for(int i=0;i<=cap;i++) {
        if(max <dp[m-1][i]) max =  dp[m-1][i];
    }
      
    return max;
}


int main() {
    
    vector<int> weights={5,6,4,3,8,4,2};
    vector<int> values={10,1,6,9,3,4,2};
    int cap = 13;
    printf("%d\n",maxValue(weights, values, cap));
    
    vector<int> weights_1={6,1,6,1};
    vector<int> values_1={2,5,6,2};
    int cap_1 = 15;
    printf("%d\n",maxValue(weights_1, values_1, cap_1));
    
    
    vector<int> weights_2={9,3};
    vector<int> values_2={9,6};
    int cap_2 = 19;
    printf("%d\n",maxValue(weights_2, values_2, cap_2));
    
    
    vector<int> weights_3={2,1,5,4,7,4,1,7};
    vector<int> values_3={4,6,7,1,1,3,2,2};
    int cap_3 = 20;
    printf("%d\n",maxValue(weights_3, values_3, cap_3));
    
    
    
    return 0;
}
