class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        int mini = INT_MAX;
        for(int i=0;i+k-1<n;i++){
            mini = min(mini,nums[i] - nums[i+k-1]);
        }
        return mini;
    }
};