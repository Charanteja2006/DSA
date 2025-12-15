class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = 0;
        int l = 0;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1) continue;
            else{
                long long len = i - l;
                res += ((len)*(len+1))/2;
                l = i;
            }
        }
        long long len = n - l;
        res += (long long)((len)*(len+1))/2;
        return res;
    }
};