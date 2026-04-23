class Solution {
public: 

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp;
        vector<long long> ans(n,0);

        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        for(auto &it:mp){
            auto &v = it.second;

            long long sum = accumulate(v.begin(),v.end(),0LL);
            int m = v.size();
            long long left = 0;

            for(int i=0;i<m;i++){
                long long right = sum - left - v[i];
                ans[v[i]] = (1LL*i*v[i] - left) + (right - 1LL*(m-i-1)*v[i]);
                left += v[i];
            }
        }

        return ans;
    }
};