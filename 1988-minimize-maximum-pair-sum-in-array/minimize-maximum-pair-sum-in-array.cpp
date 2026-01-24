class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int n = nums.size();
        int l = 0,r = n-1;
        while(l<r){
            maxi = max(maxi,nums[l] + nums[r]);
            l++;
            r--;
        }
        return maxi;
    }
};