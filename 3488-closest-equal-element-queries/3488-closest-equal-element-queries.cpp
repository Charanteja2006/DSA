class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int it = queries[i];
            int num = nums[it];
            auto& v = mp[num];

            auto ite = lower_bound(v.begin(), v.end(), it);
            int m = v.size();
            int ind = ite - v.begin();

            if (m == 1) {
                ans[i] = -1;
            } else if (ind == 0) {
                ans[i] = min(v[ind] + (n - v[m - 1]), v[ind + 1] - v[ind]);
            } else if (ind == m - 1) {
                ans[i] = min(v[ind] - v[ind - 1], v[0] + (n - v[ind]));
            } else {
                ans[i] = min(v[ind] - v[ind - 1], v[ind + 1] - v[ind]);
            }
        }

        return ans;
    }
};