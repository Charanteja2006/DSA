class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;

    void backtrack(int start, const string& s, vector<vector<bool>>& dp) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                cur.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        backtrack(0, s, dp);
        return res;
    }
};