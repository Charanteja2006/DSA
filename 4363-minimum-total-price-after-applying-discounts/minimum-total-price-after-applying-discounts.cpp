class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.rbegin(),discounts.rend());
        sort(prices.rbegin(),prices.rend());
        int n = prices.size();
        int m = discounts.size();

        double res = 0;
        int j = 0;

        for(int i=0;i<n;i++){
            if(j<m) {
                res +=  (double)(prices[i]*(100-discounts[j]*1.0))/100.0;
                j++;
            }
            else res += prices[i];
        }

        return res;
    }
};