class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        vector<int> dis(n,1e9);
        dis[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int tot = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(node == n-1) return tot;
            for(auto it:adj[node]){
                int adjn = it.first;
                int w = it.second;
                if(dis[adjn] > tot + w){
                    pq.push({tot+w,adjn});
                    dis[adjn] = tot + w;
                }
            }
        }
        return -1;
    }
};