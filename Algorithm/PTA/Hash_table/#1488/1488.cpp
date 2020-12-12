class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int  n =rains.size();
        //answers
        vector<int> ans(n,-1);
        //lake -> last rainy day
        unordered_map<int,int> last_rain;
        //days of sunny
        set<int> suns;
        for(int i=0 ;i<n ;++i){
            //collect the lake that might be rain
            const int lake=rains[i];
            //if it is sunny day
            if(lake==0){
                //collect the sunny day
                suns.insert(i);
                //dry lake 1 if it is not used
                ans[i]=1;
            }else{
                // if the lake if already full , dry it
                if(last_rain.count(lake)){
                    //find the first sunny day after first rain
                    auto it =suns.upper_bound(last_rain[lake]);
                    //if not found , no way to fix it
                    if(it ==end(suns))
                        return {};
                    //mark that day for fix
                    ans[*it]=lake;
                    //delete that sunny day
                    suns.erase(it);
                }
                //Record the last sunny day
                last_rain[lake]=i;
            }
                
            }
        return ans;
        
        }
    };