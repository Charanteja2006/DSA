class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& a) {
        vector<long long> ans;
        for (int i = 0; i < a.size(); i++) {
            long long curr = a[i];
            while (ans.size() && ans.back() == curr) {
                ans.pop_back();
                curr *= 2;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};