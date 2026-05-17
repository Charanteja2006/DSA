class Solution {
public:

    void find(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> &v){
        int n = v.size();
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        find(ind+1,ds,ans,v);
        ds.push_back(v[ind]);
        find(ind+1,ds,ans,v);
        ds.pop_back();
        return;
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,ds,ans,nums);
        return ans;
    }
};