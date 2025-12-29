class Solution {
public:
    map<string,vector<char>> mp;
    map<string,bool> dp;

    bool find(string s,string old,int ind,int n){
        if(n==1) return true;

        else if(ind==n-1){
            if(dp.count(s)) return dp[s];
            return find("",s,0,n-1);
        }

        string st = old.substr(ind,2);
        if(mp.count(st)==0) return dp[old] = false;
        for(char it:mp[st]){
            bool res = find(s+it,old,ind+1,n);
            if(res) return true;
            dp[old] = res;
        }
        return dp[old] = false;
    } 

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        for(auto it:allowed){
            mp[it.substr(0,2)].push_back(it[2]);
        }
        return find("",bottom,0,n);
    }
};