class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        vector<vector<long long>> pref(n,vector<long long> (m,1)),suff(n,vector<long long> (m,1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i][j] = grid[i][j];
                if(j==0 && i!=0) pref[i][j] = (pref[i][j]*pref[i-1][m-1])%MOD;
                else if(j!=0) pref[i][j] = (pref[i][j-1]*pref[i][j])%MOD;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suff[i][j] = grid[i][j];
                if(j==m-1 && i!=n-1) suff[i][j] = (suff[i][j]*suff[i+1][0])%MOD;
                else if(j!=m-1) suff[i][j] = (suff[i][j]*suff[i][j+1])%MOD;
            }
        }

        vector<vector<int>> res(n,vector<int> (m,1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 && i!=0) res[i][j] = (res[i][j]*pref[i-1][m-1])%MOD;
                else if(j!=0) res[i][j] = (res[i][j]*pref[i][j-1])%MOD;

                if(j==m-1 && i!=n-1) res[i][j] = (res[i][j]*suff[i+1][0])%MOD;
                else if(j!=m-1) res[i][j] = (res[i][j]*suff[i][j+1])%MOD;
            }
        }

        return res;
    }
};