class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        int i = 1,len = 0;
        while(i<n){
            if(s[i] == s[len]){
                lps[i++] = ++len;
            }
            else{
                if(len!=0) len = lps[len-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        len = lps[n-1];
        if(len>0 && n%(n-len)==0) return true;
        return false;
    }
};