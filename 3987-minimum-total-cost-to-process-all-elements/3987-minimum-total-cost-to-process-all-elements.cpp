class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int cost = k;
        long long ops = 0;
        int mini = 0;
        for(int i=0;i<nums.size();i++){
            if(cost < nums[i]){
                int req = (nums[i] - cost + (k - 1))/k;
                cost +=  req*k ;
                ops += req;
            }
            cost -= nums[i];
        }

        int MOD = 1e9 + 7;

        if (ops % 2 == 0)
            return ((ops / 2) % MOD) * ((ops + 1) % MOD) % MOD;

        return (ops % MOD) * (((ops + 1) / 2) % MOD) % MOD;
        
    }
};