class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int count =0;
        while(!false){
            bool flag = true;
            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){
                    flag = false;
                    break;
                }
            }

            if(flag) break;
            int mini = INT_MAX ;
            int ind = -1;
            for(int i=0;i<nums.size()-1;i++){
                int sum = nums[i]+nums[i+1];
                if(mini>sum){
                    mini = sum;
                    ind = i;
                }
            }
            vector<int> dup;
            for(int i=0;i<nums.size();i++){
                if(i==ind){
                    dup.push_back(nums[i]+nums[i+1]);
                    i++;
                }
                else{
                 dup.push_back(nums[i]);
                }
            }

            nums = dup;
            count++;
        }

        return count;
    
    }
};