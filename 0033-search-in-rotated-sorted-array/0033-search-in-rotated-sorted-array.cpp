class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0,r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(l<n && nums[l]==target) return l;
            if(r>=0 && nums[r]==target) return r;
            if(nums[l]>target) l = mid + 1;
            else r = mid - 1;
        }

        if(l<n && nums[l]==target) return l;
        if(r>=0 && nums[r]==target) return r;
        return -1;

    }
};