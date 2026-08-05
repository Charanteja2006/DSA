class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n);
    

        vector<int> vis(n,0);
        for(auto it:inv){
            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;
        vis[k] = 1;
        q.push(k);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        vector<int> res;
        for(auto it:inv){
            if(!vis[it[0]] && vis[it[1]]){
                for(int i=0;i<n;i++) res.push_back(i);
                return res;
            }
        }


        for(int i=0;i<n;i++) if(!vis[i]) res.push_back(i);
        return res;

        
    }
};