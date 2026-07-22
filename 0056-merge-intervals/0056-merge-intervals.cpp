class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        int st = intervals[0][0],en = intervals[0][1];
        for(int i=1;i<n;i++){
            if(en>=intervals[i][0]) en = max(en,intervals[i][1]);
            else{
                res.push_back({st,en});
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }
        res.push_back({st,en});
        return res;
    }
};