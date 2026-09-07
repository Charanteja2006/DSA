class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long tot = accumulate(nums.begin(),nums.end(),0LL);
        int n = nums.size();
        int res = 0;
        long long  cur = 0;
        
        for(int i=0;i<n/2;i++) cur += nums[i];

        for(int i=0;i<n;i++){
            if(cur > (tot-cur)) res++;
            cur -=  nums[i];
            cur += nums[(i + n/2)%n];
        }

        return res;
    }
};