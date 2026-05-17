class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<int> vis(n,0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(arr[cur]==0) return true;
            if(cur - arr[cur]>=0 && !vis[cur - arr[cur]]){
                q.push(cur-arr[cur]);
                vis[cur - arr[cur]] = 1;
            }
            if(cur + arr[cur]<n && !vis[cur + arr[cur]]){
                q.push(cur+arr[cur]);
                vis[cur + arr[cur]] = 1;
            }
        }

        return false;
    }
};