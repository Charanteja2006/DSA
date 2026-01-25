class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(nums[i]>=0) v.push_back(nums[i]); 
        }
        int m = v.size();
        if(m==0) return nums;
        k %= m;
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());
        reverse(v.begin(),v.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i] = v[j];
                j++;
            }
        }
        return nums;
    }
};