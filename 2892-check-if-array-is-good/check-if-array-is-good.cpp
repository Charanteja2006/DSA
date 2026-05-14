class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i==n-1||i==n-2) {
                if(nums[i]!=n-1) return false;
            }
            else if(i+1!=nums[i]) return false;
        }

        return true;
    }
};