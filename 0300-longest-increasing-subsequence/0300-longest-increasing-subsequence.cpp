class Solution {
public:

    int find(int i,int pre,vector<int> &nums,vector<vector<int>> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i][pre+1]!=-1) return dp[i][pre+1];
        int len = find(i+1,pre,nums,dp);
        if(pre==-1||nums[i]>nums[pre]){
            len = max(len,1+find(i+1,i,nums,dp));
        }
        return dp[i][pre+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return find(0,-1,nums,dp);
    }
};