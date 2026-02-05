class Solution {
public:

    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i=0,j=0;
        while(i<n){
            if(nums[j]>0){
                j = (nums[j] + j)%n;
            }
            else if(nums[j]<0){
                j = (j - abs(nums[j])%n + n)%n;
            }
            res[i] = nums[j];
            i++;
            j = i;
        }
        return res;
    }
};