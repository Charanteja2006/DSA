class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int tot = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if((double)nums[i]>(double)(tot/((n-i-1)*1.0))) count++;
            tot += nums[i];
        }

        return count;
    }
};