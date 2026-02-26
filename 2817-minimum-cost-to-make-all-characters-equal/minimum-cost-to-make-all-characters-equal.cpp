class Solution {
public:
    long long minimumCost(string s) {
        long long count = 0;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) count += min(i,n-i);
        }

        return count;
    }
};