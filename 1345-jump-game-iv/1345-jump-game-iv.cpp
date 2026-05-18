class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> dist(n, INT_MAX);

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            int d = dist[node];

            // Reached end
            if(node == n - 1)
                return d;

            // Same value jumps
            for(int nxt : mp[arr[node]]) {
                if(dist[nxt] == INT_MAX) {
                    dist[nxt] = d + 1;
                    q.push(nxt);
                }
            }

            // IMPORTANT: avoid reprocessing
            mp.erase(arr[node]);

            // node - 1
            if(node - 1 >= 0 && dist[node - 1] == INT_MAX) {
                dist[node - 1] = d + 1;
                q.push(node - 1);
            }

            // node + 1
            if(node + 1 < n && dist[node + 1] == INT_MAX) {
                dist[node + 1] = d + 1;
                q.push(node + 1);
            }
        }

        return -1;
    }
};