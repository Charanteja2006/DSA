class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        for(int i=n-1;i>=1;i--){
            count += nums[i] - nums[0];
        }
        return count;
    }
};


