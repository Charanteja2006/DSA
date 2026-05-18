class Solution {
public:
    int longestCommonSubsequence(string txt1, string txt2) {
        int n = txt1.size();
        int m = txt2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(txt1[i-1]==txt2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }

        return dp[n][m];
    }
};