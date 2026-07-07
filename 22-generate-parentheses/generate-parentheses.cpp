class Solution {
public:
    void find(int l,int r,vector<string> &res,string cur,int n){
        if(l+r == 2*n){
            res.push_back(cur);
            return;
        }

        if(l<n) find(l+1,r,res,cur + '(' , n);
        if(r<l) find(l,r+1,res,cur + ')' , n);

        return;

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        find(0,0,res,"",n);
        return res;
    }
};