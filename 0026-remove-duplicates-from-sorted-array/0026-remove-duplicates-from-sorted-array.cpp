class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int i = 0,j=1;
        while(j<n){
            if(nums[j]==nums[j-1]) j++;
            else{
                nums[i+1] = nums[j];
                i++;
                j++;
                count++;
            }
        }
        return count;        
    }
};