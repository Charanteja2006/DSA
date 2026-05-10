class Solution {
public:

    bool check(vector<vector<pair<int,int>>> &adj,
               int src,
               int tar,
               int threshold,
               int k){

        int n = adj.size();

        deque<int> dq;

        vector<int> dist(n, 1e9);

        dist[src] = 0;

        dq.push_front(src);

        while(!dq.empty()){

            int node = dq.front();
            dq.pop_front();

            for(auto &[next, wt] : adj[node]){

                int cost = (wt > threshold);

                if(dist[node] + cost < dist[next]){

                    dist[next] = dist[node] + cost;

                    if(cost == 0)
                        dq.push_front(next);
                    else
                        dq.push_back(next);
                }
            }
        }

        return dist[tar] <= k;
    }

    int minimumThreshold(int n,
                         vector<vector<int>>& edges,
                         int source,
                         int target,
                         int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        int l = 0;
        int r = 1e9;

        int ans = -1;

        while(l <= r){

            int mid = l + (r - l)/2;

            if(check(adj, source, target, mid, k)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};