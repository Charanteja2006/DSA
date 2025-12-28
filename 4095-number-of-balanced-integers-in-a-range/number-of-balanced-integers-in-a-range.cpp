class Solution {
public:
    string n;
    long long dp[25][205][3];

    long long solve(int ind, int bal, bool bound, bool tak) {
        
        if (ind == n.size()) {
            return (tak && bal == 0);
        }

        if (!bound && dp[ind][bal + 100][tak] != -1)
            return dp[ind][bal + 100][tak];

        long long ways = 0;
        int up = bound ? n[ind]-'0':9;

        for (int dig = 0; dig <= up; dig++) {
            
            bool ntaken = tak || dig != 0;
            int nbal = bal;

            if (ntaken) {
                
                int leftm = ind + 1;
                if (leftm & 1)
                    nbal -= dig;
                else
                    nbal += dig;
            }

            ways += solve(ind + 1, nbal, bound && dig == up, ntaken);
        }

        if (!bound)  dp[ind][bal + 100][tak] = ways;

        return ways;
    }

    long long countUpTo(long long x) {
        if (x < 10) return 0; 
        n = to_string(x);
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, true, false);
    }

    long long countBalanced(long long low, long long high) {
        return countUpTo(high) - countUpTo(low - 1);
    }
};
