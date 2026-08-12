class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        int maxi = 0;
        int l = 0;;
        for(int r = 0;r < n;r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};