class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& newI) {
        vector<vector<int>> ans;
        int l = newI[0];
        int r = newI[1];
        int n = inte.size();
        
        int i = 0;
        while(i<n && inte[i][1]<l){
            ans.push_back(inte[i]);
            i++;
        }

        while(i<n && inte[i][0]<=r){
            l = min(l,inte[i][0]);
            r = max(r,inte[i][1]);
            i++;
        }
        ans.push_back({l,r});

        while(i<n){
            ans.push_back(inte[i]);
            i++;
        }

        return ans;
    }
};