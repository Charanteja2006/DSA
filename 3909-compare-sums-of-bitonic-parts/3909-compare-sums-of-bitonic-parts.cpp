class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[i+1]){
                ind = i;
                break;
            }
        }
        
        long long sum1 = accumulate(nums.begin(),nums.begin()+ind+1,0LL);
        long long sum2 = accumulate(nums.begin()+ind,nums.end(),0LL);

        if(sum1>sum2) return 0;
        else if(sum1<sum2) return 1;
        else return -1;
    }
};