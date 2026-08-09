class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long cur = 0;
        for(int i = 1;i<n;i++){
            long long dif = nums[i-1] - nums[i];
            if(dif==0) cur = 0;
            if(dif>cur){
                sum += dif - cur;
                cur = dif;
                nums[i] = nums[i-1];
            } 
            else cur = 0;
        }

        return sum;
    }
};