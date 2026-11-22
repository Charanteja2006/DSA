class Solution {
public:
    bool checkString(string s) {
        int c = 0;
        
        for(int i=0;i<s.size() - 1;i++){
            if(s[i] != s[i+1]) c++;
        }

        if(s[0]=='b' && c>0) return false;
        return c<2;
    }
};