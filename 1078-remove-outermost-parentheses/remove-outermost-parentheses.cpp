class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res = "";

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(cnt>0) res += '(';
                cnt++;
            }
            else{
                if(cnt>1) res += ')';
                cnt--;
            }
        }

        return res;
    }
};