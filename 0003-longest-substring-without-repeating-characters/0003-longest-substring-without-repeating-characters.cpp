class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> m(256,-1);
        int k=s.size();
        if(k==0) return 0;
        int l=0,r=0,maxl=0;
        while(r<k)
        {
            if(m[s[r]]!=-1)
            {
                if(m[s[r]]>=l)
                l=m[s[r]]+1;
            }
            m[s[r]]=r;
            maxl=max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
};