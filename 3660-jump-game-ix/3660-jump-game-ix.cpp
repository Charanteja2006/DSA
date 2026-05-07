class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n,INT_MIN),suf(n,INT_MAX);
        pre[0] = nums[0];
        for(int i=1;i<n;i++) pre[i] = max(pre[i-1],nums[i]);
        suf[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) suf[i] = min(suf[i+1],nums[i]);

        vector<int> ans(n,0);
        ans[n-1] = pre[n-1];

        for(int i=n-2;i>=0;i--){
            if(pre[i]>suf[i+1]) ans[i] = ans[i+1];
            else ans[i] = pre[i];
        }

        return ans;
    }
};