class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n+1);

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        queue<pair<int,int>> q;
        q.push({1,INT_MAX});

        while(!q.empty()){
            int cur = q.front().first;
            int val = q.front().second;
            q.pop();
            if(dis[cur]<val) continue;
                
            for(auto it:adj[cur]){
                val = min(val,it[1]);
                if(val<dis[it[0]]){
                    dis[it[0]] = val;
                    q.push({it[0],val});
                }
            }
        }

        return dis[n];
    }
};