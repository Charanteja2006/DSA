class Solution {
public:
    char cyclicShift(char c, int k) {
        k %= 26;  
        return char('a' + (c - 'a' + k) % 26);
    }

    long long countPairs(vector<string>& words) {
        long long ans = 0;
        int n = words.size();
        int m = words[0].size();
        map<string,int> mp;
        for(int i=0;i<n;i++){
            string temp = "";
            int k = (26 - (words[i][0] - 'a'));
            for(int j=0;j<m;j++){
                temp += cyclicShift(words[i][j],k);
            }
            ans += mp[temp];
            mp[temp]++;
        }
        return ans;
    }
};