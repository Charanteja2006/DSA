class Solution {
public:
    int rob1(vector<int>& nums,int st,int end) {
        int n = nums.size();

        vector<int> dp(n,0);
        dp[st] = nums[st];

        for(int i=st+1;i<=end;i++){
            int take = nums[i];
            if(i>1) take += dp[i-2];
            int nottake = dp[i-1];

            dp[i] = max(take,nottake);
        }
        
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(rob1(nums,0,n-2),rob1(nums,1,n-1));
    }
};