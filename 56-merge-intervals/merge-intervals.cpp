class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 1;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        vector<int> cur = intervals[0];
        while(i<n){
            if(cur[1]<intervals[i][0]){
                res.push_back(cur);
                cur = intervals[i];
            }
            if(cur[1]>=intervals[i][0]){
                cur[1] = max(intervals[i][1],cur[1]);
            }
            i++;
        }
        
        res.push_back(cur);

        return res;
    }
};