class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = ranges::max(nums);
        int mini = ranges::min(nums);

        return gcd(mini,maxi);
    }
};