class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<int> dsu(n,0);

        for(int i=1;i<n;i++){
            dsu[i] = dsu[i-1] + (nums[i]-nums[i-1] > maxDiff);
        } 

        for(auto it:queries){
            if(dsu[it[0]]==dsu[it[1]]) res.push_back(1);
            else res.push_back(0);
        }

        return res;
    }
};