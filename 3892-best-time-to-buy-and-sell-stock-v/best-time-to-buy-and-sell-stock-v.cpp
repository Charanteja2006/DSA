class Solution {
public:
    long long find(vector<int>& v,int k,int tran,int i,vector<vector<vector<long long>>>& dp){
        if(dp[i][tran][k]!=LONG_MIN) return dp[i][tran][k];
        if(k==0) return 0;
        if(i==v.size()-1){
            if(tran==0) return 0;
            else if(tran==1) return v[i];
            return -v[i];
        }
        long long prof = 0;
        if(tran==0){
            prof = v[i] + find(v,k,2,i+1,dp);
            prof = max(prof,-v[i]+find(v,k,1,i+1,dp));
            prof = max(prof,find(v,k,0,i+1,dp));
        }
        else if(tran==2){
            prof = max(-v[i]+find(v,k-1,0,i+1,dp),find(v,k,2,i+1,dp));
        }
        else prof =  max(v[i]+find(v,k-1,0,i+1,dp),find(v,k,1,i+1,dp));
        return dp[i][tran][k] = prof;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>> (3, vector<long long> (k+1,LONG_MIN)));
        return find(prices,k,0,0,dp);
    }
};