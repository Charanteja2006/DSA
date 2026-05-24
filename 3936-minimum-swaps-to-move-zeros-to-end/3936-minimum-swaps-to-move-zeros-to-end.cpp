class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ,r = n - 1;
        int count = 0;
        while(l<r){
            while(l<r && nums[r]==0) r--;
            while(l<r && nums[l]!=0) l++;
            if(r>=0 && l<r && nums[r]!=0){
                count++;
                r--;
                l++;
            }
        }

        return count;
    }
};