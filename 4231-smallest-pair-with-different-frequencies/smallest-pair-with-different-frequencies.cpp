class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        int x = -1,y=-1,mini=-1;
        for(auto it:mp){
            if(x==-1){
                x = it.first;
                mini = it.second;
            }
            else if(mini!=it.second){
                y = it.first;
                break;
            }
        }

        if(y==-1) return {-1,-1};
        return {x,y};
    }
};