class Solution {
public:
    bool pal(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void find(int i,int j,vector<vector<string>> &res,vector<string>& cur ,string s){
        int n = s.size();
        if(j==n-1){
            if(pal(i,j,s)){
                cur.push_back(s.substr(i,j-i+1));
                res.push_back(cur);
                cur.pop_back();
            }    
            return;
        }

        if(pal(i,j,s)){
            cur.push_back(s.substr(i,j-i+1));
            find(j+1,j+1,res,cur,s);
            cur.pop_back();
        }   

        find(i,j+1,res,cur,s);
        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        find(0,0,res,cur,s);
        return res;
    }
};