class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<long long>> mini(26,vector<long long> (26,LLONG_MAX));
        for(int i=0;i<original.size();i++){
            int a = original[i]-'a';
            int b = changed[i]-'a';
            mini[a][b] = min(mini[a][b],(long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(mini[i][k]==LLONG_MAX || mini[k][j]==LLONG_MAX) continue;
                    mini[i][j] = min(mini[i][j],mini[i][k] + mini[k][j]);
                }
            }
        }

        long long tot = 0;
        for(int i=0;i<n;i++){
            if(source[i] != target[i]){
                int a = source[i] - 'a';
                int b = target[i] - 'a';
                if(mini[a][b]==LLONG_MAX) return -1;
                tot += mini[a][b];
            }
        }

        return tot;
    }
};