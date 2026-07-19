class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int MOD = 1e9 + 7;

        int ops = 0;

        vector<int> temp;
        int l = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<a){
                ops = (ops + i-l)%MOD;
                l++;
            }
            else temp.push_back(nums[i]);
        }
        l = 0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>=a && temp[i]<=b){
                ops = (ops + i-l)%MOD;
                l++;
            }
        }
        
        return ops;
    }
};