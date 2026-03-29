class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        set<char> s1e,s2e,s1o,s2o;
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1e.insert(s1[i]);
                s2e.insert(s2[i]);
            }
            else{
                s1o.insert(s1[i]);
                s2o.insert(s2[i]);
            }
        }

        return s1e==s2e&&s1o==s2o;
    }
};