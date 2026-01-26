class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj,int x){
        int n = adj.size();
        vector<int> dis(n,0);
        vector<int> vis(n,0);
        queue<int> q;
        int h = 1;
        q.push(x);
        vis[x] = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                            q.push(it);
                            dis[it] = h;
                            vis[it] = 1;
                    }
                }
            }
            h++;
        }
        return dis;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        auto dx = bfs(adj,x);
        auto dy = bfs(adj,y);
        auto dz = bfs(adj,z);

        int  count = 0;
        for(int i=0;i<n;i++){
            long long a = dx[i], b = dy[i], c = dz[i];

            if (a > b) { long long t = a; a = b; b = t; }
            if (b > c) { long long t = b; b = c; c = t; }
            if (a > b) { long long t = a; a = b; b = t; }

            count += int(a * a + b * b == c * c);
        }

        return count;
    }
};