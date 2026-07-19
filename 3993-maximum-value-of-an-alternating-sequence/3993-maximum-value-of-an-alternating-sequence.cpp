class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        
        long long res = s+m;
        res += 1LL*((n-2)/2)*(m-1);
        
        return res;
    }
};




