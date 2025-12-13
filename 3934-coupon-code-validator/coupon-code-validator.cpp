class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& b, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string,string>> valid;
        for(int i=0;i<n;i++){
            if(code[i] == "") continue;
            else{
                bool f = true;
                for(char c : code[i]){
                    if(!(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9' || c=='_' )){
                        f = false;
                    }
                }
                if(b[i]!="electronics"&&b[i]!="grocery"&&b[i]!="pharmacy"&&b[i]!="restaurant") f = false;
                if(!isActive[i]) f = false;
                if(f) valid.push_back({b[i],code[i]});
            }
        }
        sort(valid.begin(),valid.end());
        vector<string> res;
        for(auto it : valid){
            res.push_back(it.second);
        }
        return res;
    }
};