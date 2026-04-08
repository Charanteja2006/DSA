class Solution {
public:
    const int mod = 1e9 + 7;
    
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(auto &it:queries){
            int l = it[0],r = it[1],k = it[2] ,v = it[3];
            for(int j = l;j<=r;j+=k){
                long long res = (1LL*nums[j]*v)%mod;
                nums[j] = int(res);
            }
        }
        int res = 0;
        for(auto it:nums) res ^= it;
        return res;
    }
};