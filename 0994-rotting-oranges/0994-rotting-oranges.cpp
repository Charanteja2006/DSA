class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1}; 
        int tm = 0;
        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int ii=0;ii<4;ii++){
                    int nrow = row + drow[ii];
                    int ncol = col + dcol[ii];
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0  && grid[nrow][ncol]==1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(!q.empty()) tm++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1) return -1;
            }
        }
        return tm;
    }
};