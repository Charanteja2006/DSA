class Solution {
public:
    bool solve(int node,vector<int>& col,vector<vector<int>>& graph){
        queue<int> q;
        col[node] = 0;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:graph[node]){
                if(col[it]!=-1 && col[it]==col[node]) return false;
                else if(col[it]==-1){
                    col[it] = !col[node];
                    q.push(it);
                }
            }
        }
        return true;
    } 

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!solve(i,col,graph)) return false;
            }
        }
        return true;
    }
};