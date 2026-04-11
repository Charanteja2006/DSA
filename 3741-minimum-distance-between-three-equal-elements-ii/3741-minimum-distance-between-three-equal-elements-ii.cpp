class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int dist = INT_MAX;
        for(auto it:mp){
            int m = it.second.size();
            vector<int> num = it.second;
            if(m<3) continue;
            for(int i=0;i<m-2;i++){
                dist = min(dist,abs(num[i+1]-num[i])+abs(num[i+2]-num[i])+abs(num[i+1]-num[i+2]));
            }
        }
        if(dist==INT_MAX) return -1;
        return dist;
    }
};