class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        int pre = i;
        if(i==0) return false;
        while(i<n-1 && nums[i]>nums[i+1]) i++;
        int re = i - pre;
        pre = i;
        if(re==0) return false;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i - pre == 0) return false;
        if(i!=n-1) return false;
        return true;
    }
};