class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long ans = 0;
        for(int i=0;i<k;i++){
            ans += max(0LL, (happiness[i]-i)*1LL);
        }
        return ans;
    }
};