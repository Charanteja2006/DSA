class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(auto it:s){
            if(it>='A' && it<='Z' || it>='a' && it<='z'){
                res += tolower(it);
            }
            else if(it>='0' && it<='9') res += it;
        }
        int n = res.size();
        for(int i=0;i<n/2;i++){
            if(res[i]!=res[n-1-i]) return false;
        }
        return true;
    }
};