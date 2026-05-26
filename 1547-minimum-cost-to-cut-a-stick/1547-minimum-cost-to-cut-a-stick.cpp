class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m+1, vector<int> (m+1,0));

        for(int i=m-2;i>=1;i--){
            for(int j=i;j<=m-2;j++){
                int mini = INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][m-2];
    }
};