class Solution {
public:
    
    int check(int ind,vector<int> &coins,int target,vector<vector<int>> &dp){
        if(target==0) return 1;
        if(ind==0){
            if(target%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = check(ind-1,coins,target,dp);
        int take = 0;
        if(coins[ind]<=target){
            take = check(ind,coins,target-coins[ind],dp);
        }
        dp[ind][target] = take + nottake;
        return dp[ind][target];
    }
    
    int change(int amount,vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return check(n-1,coins,amount,dp);
    }
};