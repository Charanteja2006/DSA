class Solution {
public:
    int residuePrefixes(string s) {
        set<char> st;
        int count = 0;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
            int len = (i+1)%3;
            if(st.size() == len) count++;
        }
        return count;
    }
};