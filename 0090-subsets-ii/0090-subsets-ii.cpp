class Solution {
public:
    void find(int ind,vector<int> &v,vector<int> &ds,vector<vector<int>> &ans){
        int n = v.size();
        ans.push_back(ds);
        for(int i=ind;i<n;i++){
            if(i!=ind && v[i]==v[i-1]) continue;
            ds.push_back(v[i]);
            find(i+1,v,ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,nums,ds,ans);

        return ans;
    }
};