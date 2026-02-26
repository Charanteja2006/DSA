class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = chars.size();
        map<char,int> mp;
        for(int i=0;i<n;i++)
            mp[chars[i]] = vals[i];
        for(int i=0;i<26;i++){
            char c = 'a' + i;
            if(mp.count(c)) continue;
            else mp[c] = i+1;
        }

        int maxi = 0;
        int cur = 0;
        for(int i=0;i<s.size();i++){
            if(cur<0) cur = 0;
            cur += mp[s[i]];
            maxi = max(maxi,cur);
        }

        return maxi;
    }
};