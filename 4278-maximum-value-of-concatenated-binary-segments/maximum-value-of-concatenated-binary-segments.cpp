class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> v;
        int n = nums1.size();
        long long MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){
            v.push_back({nums1[i], nums0[i]});
        }

    
        sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b){
           
            int v1[] = {a.first, a.second, b.first, b.second}; 
            int t1[] = {1, 0, 1, 0};                           
            
        
            int v2[] = {b.first, b.second, a.first, a.second}; 
            int t2[] = {1, 0, 1, 0};                          
            
            int i = 0, j = 0;
            while(i < 4 && j < 4) {
                if(v1[i] == 0) { i++; continue; }
                if(v2[j] == 0) { j++; continue; }
                
            
                if(t1[i] != t2[j]) {
                    return t1[i] > t2[j]; 
                }

                int mn = min(v1[i], v2[j]);
                v1[i] -= mn;
                v2[j] -= mn;
            }
            return false;
        });

        long long val = 0;
        for(auto it : v){
            int v1 = it.first;
            int v0 = it.second;
            

            if (v1 > 0) {
                long long p1 = power(2, v1);
                val = (val * p1 % MOD + p1 - 1) % MOD;
            }

            if (v0 > 0) {
                long long p0 = power(2, v0);
                val = (val * p0) % MOD;
            }
        }

        return (int)val;
    }
};