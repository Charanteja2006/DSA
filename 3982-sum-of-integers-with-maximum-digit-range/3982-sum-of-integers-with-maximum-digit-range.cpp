class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> mp(10,0);
        
        for(auto it:nums){
            int num = it;
            int sm = INT_MAX,la = INT_MIN;

            while(num>0){
                sm = min(sm,num%10);
                la = max(la,num%10);
                num /= 10;
            }
            mp[la-sm] += it;
        }

        for(int i=9;i>=0;i--){
            if(mp[i]>0) return mp[i];
        }

        return 0;

    }
};