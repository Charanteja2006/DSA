class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        map<int,int> mp;
        for(auto it:nums){
            int num = it;
            while(num>0){
                mp[num%10]++;
                num/=10;
            }
        }

        return mp[digit];
    }
};