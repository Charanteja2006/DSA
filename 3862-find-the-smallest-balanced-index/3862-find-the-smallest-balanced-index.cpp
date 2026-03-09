class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1] + nums[i];
        long long maxi = 1e12;
        long long prod = 1;
        int mini = n + 1;
        for(int i=n-1;i>=1;i--){
            if(prod == pref[i-1]) return i;
            if(prod > pref[i-1]) break;
            prod *= nums[i];
        }

        return -1;
    }
};