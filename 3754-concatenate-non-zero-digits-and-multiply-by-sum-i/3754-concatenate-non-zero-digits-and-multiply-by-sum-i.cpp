class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long res = 0;
        long long sum = 0;
        for(auto it:s){
            if(it!='0'){
                res = res*10 + (it-'0');
                sum += (it-'0');
            }
        }

        return res*sum;
    }
};