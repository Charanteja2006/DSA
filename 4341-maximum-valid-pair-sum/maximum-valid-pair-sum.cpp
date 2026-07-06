class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int n = nums.size(); 
        int res = 0;
        for(int i=k;i<n;i++){
            maxi = max(maxi,nums[i-k]);
            res = max(res,maxi + nums[i]);
        }  

        return res;
    }
};