class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        for(auto it:knowledge){
            mp[it[0]] = it[1];
        }

        string res = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                string st = "";
                i++;
                while(i<n && s[i]!=')'){
                    st += s[i];
                    i++;
                }
               
                if(mp.count(st)) res += mp[st];
                else res += '?';
            }
            else res += s[i];
        }

        return res;
    }
};