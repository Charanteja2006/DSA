class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for(int i=0;i<n;i++){
            if(nums[i]==2) res.push_back(-1);
            else{
                for(int j=0;j<31;j++){
                    if((nums[i] & (1<<j)) == 0){
                        res.push_back(nums[i]^(1<<(j-1)));
                        break;
                    }
                }
            }
        }
        return res;
    }

};