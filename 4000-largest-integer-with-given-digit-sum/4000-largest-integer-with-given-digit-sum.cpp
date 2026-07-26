class Solution {
public:
    int largestInteger(int n, int s) {
        int in = 0;
        int res = 0;
        while(in<n){
            if(s==0) res *= 10;
            else if(s<10){
                res = res*10 + s;
                s = 0;
            }
            else {
                res = res*10 + 9;
                s -= 9;
            }
            in++;
        }
        if(s>0) return -1;
        return res;
    }
};