class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);

        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});  
        dis[0] = dis[k] = 0;

        while(!q.empty()){
            int node = q.top().second;
            int time = q.top().first;
            q.pop();

            if(dis[node]<time) continue;

            for(auto it:adj[node]){
                if(dis[it[0]] > time + it[1]){
                    dis[it[0]] = time + it[1];
                    q.push({dis[it[0]],it[0]});
                }
            }
        }

        int res = *max_element(dis.begin(),dis.end());
        return res==INT_MAX ? -1 : res;
    }
};