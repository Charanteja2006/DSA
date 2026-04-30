class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (k+1,-1)));
        dp[0][0][0] = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int c=0;c<=k;c++){
                    if(dp[i][j][c]==-1) continue;
                    
                    if(i+1<n){
                        int nc = grid[i+1][j]>0?1:0;
                        if(c+nc<=k) 
                            dp[i+1][j][c+nc] = max(dp[i+1][j][c+nc],dp[i][j][c]+grid[i+1][j]);
                    }
                    if(j+1<m){
                        int nc = grid[i][j+1]>0?1:0;
                        if(c+nc<=k) 
                            dp[i][j+1][c+nc] = max(dp[i][j+1][c+nc],dp[i][j][c]+grid[i][j+1]);
                    }
                }
            }
        }

        int maxi = -1;
        for(int i=0;i<=k;i++){
            maxi = max(maxi,dp[n-1][m-1][i]);
        }

        return maxi;
    }
};