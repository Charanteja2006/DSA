class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n,-1);
        dp[0] = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dp[i]==-1) continue;
                int dif = nums[j] - nums[i];
                if((-target) <= dif && dif <= target){
                    dp[j] = max(dp[j],dp[i] + 1);
                }
            }
        }

        return dp[n-1];
    }
};