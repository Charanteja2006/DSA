class Solution {
public:
    int find(int amt,vector<int>& coins,int i,vector<vector<int>>& dp){
        int n = coins.size();
        if(amt==0) return 1;
        if(i==n) return amt==0;
        if(dp[i][amt]!=-1) return dp[i][amt];
        int tot = 0;
        if(coins[i]<=amt){
            tot = find(amt-coins[i],coins,i,dp) ;
        } 
        return dp[i][amt] = tot += find(amt,coins,i+1,dp);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return find(amount,coins,0,dp);
    }
};