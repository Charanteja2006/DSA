class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int tot = 0;
        for(int i=n-1;i>=1;i--){
            tot += abs(cost[i-1] - cost[i]);
            cost[(i-1)/2] += max(cost[i-1],cost[i]);
            i--;
        }
        return tot;
    }
};