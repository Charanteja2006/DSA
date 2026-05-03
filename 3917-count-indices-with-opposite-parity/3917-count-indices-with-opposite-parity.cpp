class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int e = 0, o = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if((nums[i]&1)) o++;
            else e++;
        }

        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if((nums[i]&1)){
                ans[i] = e;
                o--;
            }
            else{
                ans[i] = o;
                e--;
            }
        }

        return ans;
    }
};