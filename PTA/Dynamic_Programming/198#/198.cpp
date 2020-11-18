#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> state=vector<int>(n,0);
        state[0]=nums[0];
        state[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
            state[i]=max(state[i-1],state[i-2]+nums[i]);
        
        return state[n-1];
    }
};