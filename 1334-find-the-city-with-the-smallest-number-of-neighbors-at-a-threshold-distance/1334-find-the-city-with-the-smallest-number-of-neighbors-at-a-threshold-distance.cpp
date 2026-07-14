class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        vector<vector<vector<int>>> adj(n);

        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]}); 
            adj[it[1]].push_back({it[0],it[2]}); 
        }

        int city = -1;
        int count = 1000;
        for(int i=0;i<n;i++){
            int c = 0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<int> dis(n,INT_MAX);
            dis[i] = 0;
            pq.push({0,i});
            while(!pq.empty()){
                int w = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if(dis[node]<w) continue;
                for(auto it:adj[node]){
                    if(dist >= (w + it[1])  && dis[it[0]] > w + it[1]){
                        dis[it[0]] = w + it[1];
                        pq.push({dis[it[0]],it[0]});
                    }
                }
            }
            for(int j=0;j<n;j++){
                if(dis[j]!=INT_MAX) c++;
            }

            if(count>=c){
                count = c;
                city = i;
            }
        }

        return city;
    }
};