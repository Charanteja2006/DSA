class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long l = *max_element(nums.begin(),nums.end());
        long long r = *min_element(nums.begin(),nums.end());
        return (long long)1LL*(l - r)*k;
    }
};