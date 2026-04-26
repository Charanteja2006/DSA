class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        int si = s.size();

        for(int i=0;i<si;i++){
            if(i==0 && (s[i] - '0'== x )) return false;
            else if(s[i]-'0' == x) return true;
        }

        return false;
    }
};