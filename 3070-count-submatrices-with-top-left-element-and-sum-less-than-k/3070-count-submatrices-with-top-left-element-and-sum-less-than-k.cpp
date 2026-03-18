class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n,vector<int> (m));
        int count = 0;

        for(int i=0;i<m;i++){
            if(i==0) v[0][i] = grid[0][i];
            else v[0][i] = v[0][i-1] + grid[0][i];
            if(v[0][i]<=k) count++;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) v[i][j] = grid[i][j] + v[i-1][j];
                else v[i][j] = grid[i][j] + v[i-1][j] - v[i-1][j-1] + v[i][j-1]; 
                if(v[i][j]<=k) count++;
            }
        }

        return count;
    }
};