class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.size();
        int l = 0,r = 0;
        int ans = 0;
        while(r<n){
            if(mp[s[r]]!=0){
                mp[s[l]]--;
                l++;
                continue;
            }
            if(mp[s[r]]==0){
                ans = max(ans,r-l+1);
                mp[s[r]]++;
                r++;
            }
        }

        return ans;
    }
};