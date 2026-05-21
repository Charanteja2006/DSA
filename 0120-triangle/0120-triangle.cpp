class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int> (n,0));

        dp[0][0] = triangle[0][0];

        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int mini = INT_MAX;
                if(j!=i) mini = triangle[i][j] + dp[i-1][j];
                if(j>0) mini = min(mini,triangle[i][j] + dp[i-1][j-1]);
                dp[i][j] = mini;
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++) mini = min(mini, dp[n-1][i]);

        return mini;

    
    }
};