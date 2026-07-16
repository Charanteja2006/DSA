class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, nums[i]);
            pref[i] = gcd(maxi,nums[i]);
        }
        sort(pref.begin(),pref.end());
        long long sum = 0;
        for(int i=0;i<n/2;i++){
            sum += gcd(pref[i],pref[n-1-i]);
        }
        
        return sum;
    }
};