class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long profit = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            profit += 1LL*prices[i]*strategy[i];
        }
        long long maxi = 0;
        int mid = k/2;
        long long fh = 0,sh=0,inran = 0;
        for(int i=0;i<mid;i++) fh += 1LL*prices[i]*strategy[i];
        for(int i=mid;i<k;i++){
            sh += 1LL*prices[i]*strategy[i];
            inran += prices[i];
        }
        maxi = inran - sh - fh;
        
        for(int l = 1;l+k<=n;l++){
            int h = l + mid - 1;
            int r = l + k - 1;
            fh -= 1LL*prices[l-1]*strategy[l-1];
            fh += 1LL*prices[h]*strategy[h];
            inran -= prices[h];
            sh -= 1LL*prices[h]*strategy[h];
            inran += prices[r];
            sh += 1LL*prices[r]*strategy[r];

            maxi = max(maxi,(long long)inran - fh - sh);
        }
        return profit + max(0LL,maxi);
    }
};