class Solution {
public:
    int find(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int val = 0;
        if(j==n || nums[i]>nums[j]){
            val =1 + find(nums,i+1,i,dp);
        }
        val = max(val,find(nums,i+1,j,dp));
        return dp[i][j] = val;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return find(nums,0,n,dp);
    }
};