class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long NEG_INF = -1e15;
        
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(2, NEG_INF)));

        dp[0][0][0] = dp[0][0][1] = grid[0][0];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;

                long long mx = NEG_INF, mn = -NEG_INF;

                if(i > 0) {
                    long long a = dp[i-1][j][0];
                    long long b = dp[i-1][j][1];
                    if(a != NEG_INF) {
                        mx = max(mx, a * grid[i][j]);
                        mn = min(mn, a * grid[i][j]);
                    }
                    if(b != NEG_INF) {
                        mx = max(mx, b * grid[i][j]);
                        mn = min(mn, b * grid[i][j]);
                    }
                }

                if(j > 0) {
                    long long a = dp[i][j-1][0];
                    long long b = dp[i][j-1][1];
                    if(a != NEG_INF) {
                        mx = max(mx, a * grid[i][j]);
                        mn = min(mn, a * grid[i][j]);
                    }
                    if(b != NEG_INF) {
                        mx = max(mx, b * grid[i][j]);
                        mn = min(mn, b * grid[i][j]);
                    }
                }

                dp[i][j][0] = mx;
                dp[i][j][1] = mn;
            }
        }

        long long res = dp[n-1][m-1][0];
        int MOD = 1e9 + 7;

        if(res < 0) return -1;
        return res % MOD;
    }
};