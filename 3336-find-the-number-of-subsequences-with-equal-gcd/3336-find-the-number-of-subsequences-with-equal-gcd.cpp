class Solution {
public:
    int MOD = 1e9 + 7;

    int cal(int i,int gcd1,int gcd2,vector<vector<int>>& gcdd,vector<vector<vector<int>>>& dp,vector<int>& v){
        int n = v.size();
        if(n==i){
            if(gcd1 && gcd2) return gcd1 == gcd2;
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1) return dp[i][gcd1][gcd2];

        long long val = 0;
        val = (val + cal(i+1,gcd1,gcd2,gcdd,dp,v))%MOD;
        val = (val + cal(i+1, (gcd1 ? gcdd[gcd1][v[i]] : v[i]),gcd2,gcdd,dp,v))%MOD;
        val = (val + cal(i+1, gcd1,(gcd2 ? gcdd[gcd2][v[i]] : v[i]),gcdd,dp,v))%MOD;

        return dp[i][gcd1][gcd2] = (int)val;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gcdd(201, vector<int> (201,0));

        vector<vector<vector<int>>> dp(n,vector<vector<int>> (201, 
                            vector<int> (201,-1)));

        for(int i=1;i<=200;i++){
            for(int j=1;j<=200;j++){
                gcdd[i][j] = __gcd(i,j);
            }
        }

        return cal(0,0,0,gcdd,dp,nums);
    }
};