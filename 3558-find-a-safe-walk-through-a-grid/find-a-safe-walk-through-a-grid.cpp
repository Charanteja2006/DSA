class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dis(n,vector<int> (m,0));
        
        dis[0][0] = grid[0][0] ? health -1 : health;
        q.push({0,0});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && dis[nr][nc]<(dis[r][c] - grid[nr][nc])){
                    dis[nr][nc] = (dis[r][c] - grid[nr][nc]);
                    q.push({nr,nc});
                }
            }
        }
        
        return dis[n-1][m-1]!=0;
    }
};