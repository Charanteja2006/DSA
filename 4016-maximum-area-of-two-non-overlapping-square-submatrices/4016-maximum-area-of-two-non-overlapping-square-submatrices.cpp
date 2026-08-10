class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {    
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Standard Maximal Square DP
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    if(i == 0 || j == 0) dp[i][j] = 1;
                    else {
                        dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                    } 
                }
            }
        }

        // Step 2: Binary Search for the maximum size of two non-overlapping squares
        int l = 1;
        int h = min(n, m);
        int ans = 0;
        
        while(l <= h) {
            int mid = l + (h - l) / 2;
            
            // Fix: Use safely large values instead of 501
            int rn = 1e9, cn = 1e9;
            int rm = -1, cm = -1;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    // Fix: If a larger square ends here, a `mid`-sized square ends here too
                    if(dp[i][j] >= mid) {
                        rn = min(rn, i);
                        cn = min(cn, j);
                        rm = max(rm, i);
                        cm = max(cm, j);
                    }
                }
            }  

            // If the max vertical distance OR max horizontal distance between 
            // valid bottom-right corners is >= mid, they don't overlap.
            bool f = (rm - rn) >= mid || (cm - cn) >= mid;
            
            if(f) {
                ans = mid;
                l = mid + 1; // Try to find a larger square
            }
            else {
                h = mid - 1; // Try a smaller square
            }
        }

        return ans * ans; // Return the area
    }
};