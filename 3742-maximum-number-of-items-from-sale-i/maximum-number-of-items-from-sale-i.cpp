class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> value(n);
        int minPrice = INT_MAX;

        for (int i = 0; i < n; i++) {
            int freebies = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    freebies++;
            }

            value[i] = 1 + freebies;   // first purchased copy + freebies
            minPrice = min(minPrice, items[i][1]);
        }

        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        // 0/1 knapsack for buying the first copy of each type
        for (int i = 0; i < n; i++) {
            int cost = items[i][1];

            for (int b = budget; b >= cost; b--) {
                dp[b] = max(dp[b], dp[b - cost] + value[i]);
            }
        }

        int ans = 0;

        for (int spent = 0; spent <= budget; spent++) {
            if (dp[spent] < 0) continue;

            int remaining = budget - spent;

            ans = max(ans,
                      dp[spent] + remaining / minPrice);
        }

        return ans;
    }
};