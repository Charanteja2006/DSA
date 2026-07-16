class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return 0;
        vector<vector<int>> adj(n);

        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        int maxi = 0;
        queue<pair<int,int>> q;
        q.push({headID,0});

        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            maxi = max(maxi,time);
            for(auto it:adj[node]){
                q.push({it,time+informTime[node]});
            }
        }


        return maxi;
    }
};