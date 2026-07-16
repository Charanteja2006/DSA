class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;

        vector<vector<vector<int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long> dis(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        
        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second; 
            pq.pop();

            if(time>dis[node]) continue;
            
            for(auto it:adj[node]){
                if(dis[it[0]]>time+it[1]){
                    dis[it[0]] = time + it[1];
                    ways[it[0]] = ways[node];
                    pq.push({dis[it[0]],it[0]});
                }
                else if(dis[it[0]]==time + it[1]){
                    ways[it[0]] = (ways[it[0]] + ways[node])%MOD;
                }
            }
        }

        return ways[n-1];
    }
};