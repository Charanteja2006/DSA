class Solution {
public:

    int rev(int n) {
        int revNum = 0;
        while (n > 0) {
            revNum = revNum * 10 + n % 10;
            n = n / 10;
        }
        return revNum;
    }

    int minMirrorPairDistance(vector<int>& nums) {

        map<int,int> mp;
        int n = nums.size();

        int ans = INT_MAX;
        
        for(int i=0;i<n;i++){

            int rn = rev(nums[i]);
            if(mp.count(nums[i])){
                ans = min(ans,i - mp[nums[i]]);
            }
            mp[rn] = i;
        }

        return ans==INT_MAX?-1:ans;
    
    }
};