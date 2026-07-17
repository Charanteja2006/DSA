class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,pair<int,int>>> q;

        q.push({1,{0,0}});
        vis[0][0] = 1;


        int dr[8] = {0,0,-1,1,1,-1,1,-1};
        int dc[8] = {-1,1,0,0,-1,1,1,-1};

        while(!q.empty()){
            int count = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1) return count; 
            for(int i=0;i<8;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && vis[nr][nc]==0){
                    q.push({count+1,{nr,nc}});
                    vis[nr][nc] = 1;
                } 
            }
        }

        return -1;
    }
};