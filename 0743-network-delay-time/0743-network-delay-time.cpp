class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int tm = it[2];
            adj[u].push_back({v,tm});
        }

        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;
        queue<pair<int,int>> q;
        q.push({k,0});

        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            if(time>dis[node]) continue;

            for(auto it:adj[node]){
                if(dis[it.first]>time+it.second){
                    dis[it.first] = time + it.second;
                    q.push({it.first,dis[it.first]});
                }
            }
        }

        int res = *max_element(dis.begin()+1,dis.end());
        return res == INT_MAX? - 1: res;
    }
};