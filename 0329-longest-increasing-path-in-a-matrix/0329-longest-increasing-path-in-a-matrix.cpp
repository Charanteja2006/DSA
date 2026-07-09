class Solution {
public:

    int solve(int r,int c,vector<vector<int>>& dp,vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};

        int maxi = 0;
        for(int i=0;i<4;i++){
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if(nr<n && nr>=0 && nc>=0 && nc<m && mat[r][c]<mat[nr][nc]){
                if(dp[nr][nc]!=-1) maxi = max(maxi,1+dp[nr][nc]);
                else maxi = max(maxi,1+solve(nr,nc,dp,mat));
            }
        }

        return dp[r][c] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int> (m,-1));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1){
                    ans = max(ans,dp[i][j]);
                }
                else{
                    ans = max(ans,solve(i,j,dp,matrix));
                }
            }
        }

        return ans+1;
    }
};