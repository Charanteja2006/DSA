class Solution {
public:
    int mirrorFrequency(string s) {
        map<int,int> mp1, mp2;
        int tot = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z') 
                mp1[s[i] - 'a']++;
            else 
                mp2[s[i] - '0']++;
        }

        vector<int> ap(26, 0);
        vector<int> dig(10, 0);

        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                int val = s[i] - 'a';

                if(!ap[val]){
                    int mirror = 25 - val;
                    tot += abs(mp1[val] - mp1[mirror]);
                    ap[val] = ap[mirror] = 1;
                }
            }
            else {
                int val = s[i] - '0';

                if(!dig[val]){
                    int mirror = 9 - val;
                    tot += abs(mp2[val] - mp2[mirror]);
                    dig[val] = dig[mirror] = 1;
                }
            }
        }

        return tot;
    }
};