class Solution {
public:
    struct Edge{
        int v;
        long long cost;
        long long tax;
    };

    vector<long long> dfs(vector<vector<Edge>>& adj,int src,bool sim){
        int n = adj.size();
        vector<long long> dis(n,1e12);
        using pii = pair<long long,int>;
        priority_queue<pii,vector<pii>,greater<pii>> pq;

        dis[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            long long dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(dist>dis[u]) continue;

            for(auto it:adj[u]){
                int v = it.v;
                long long cost = sim? it.cost:it.tax;

                if(dis[v]>cost+dist){
                    dis[v] = cost+dist;
                    pq.push({cost+dist,v});
                }
            }

        }

        return dis;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<Edge>> adj(n);

        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            int tax = it[3];

            adj[u].push_back({v,1LL*cost,1LL*cost*tax});
            adj[v].push_back({u,1LL*cost,1LL*cost*tax});
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            vector<long long> sim = dfs(adj,i,true);
            vector<long long> taxs = dfs(adj,i,false);

            ans[i] = prices[i];
            long long best = 1e12;
            for(int j=0;j<n;j++){
                if(i==j) continue;

                long long round = sim[j] + taxs[j] + prices[j];
                best = min(best,round);
            }

            ans[i] = (int)min(1LL*ans[i],best);
        }

        return ans;
    }
};