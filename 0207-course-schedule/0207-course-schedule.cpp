class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        int tot = 0;
        queue<int> q;
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            tot++;

            for(auto it:adj[node]){
                if(--indeg[it]==0) q.push(it);
            }
        }

        return tot==n;
    }
};