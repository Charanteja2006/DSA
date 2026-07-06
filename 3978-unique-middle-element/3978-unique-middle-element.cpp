class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(auto it:nums){
            mp[it]++;
        }

        return mp[nums[n/2]]==1;
    }
};