class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        long long tot = 0;
        for(int i=0;i<k;i++){
            if(mul>0){
                tot += 1LL*mul*nums[i];
                mul--;
            }
            else tot += nums[i];
        }

        return tot;
    }
};