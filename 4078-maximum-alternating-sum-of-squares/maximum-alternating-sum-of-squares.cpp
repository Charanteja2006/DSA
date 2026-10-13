class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++) nums[i] = abs(nums[i]);
        sort(nums.rbegin(),nums.rend());
        
        long long res = 0;
        for(int i=0;i<n;i++){
            if(i<n/2 || (i==n/2 && (n&1))) res += (long long)(nums[i]*nums[i]); 
            else res -= (long long)(nums[i]*nums[i]);
        }

        return res;
    }
};