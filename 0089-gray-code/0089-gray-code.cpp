class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        solve(n,res);
        return res;
    }

    void solve(int n,vector<int>& res){
        if(n==1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }
        solve(n-1,res);
        vector<int> v2 = res;
        reverse(v2.begin(),v2.end());
        res.insert(res.end(),v2.begin(),v2.end());
        int m = res.size();
        int i = m/2;
        while(i<m){
            res[i] = (1<<(n-1)) + res[i];
            i++;
        }
        return;
    }

};