class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n  = nums.size();
        int mini = INT_MAX;
        for(int i=start;i<n;i++){
            if(nums[i]==target){
                mini = abs(i-start);
                break;
            }
        }

        for(int i=start;i>=0;i--){
            if(nums[i]==target){
                mini = min(mini,abs(i-start));
                break;
            }
        }
        return mini;
    }
};