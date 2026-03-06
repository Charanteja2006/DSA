class Solution {
public:
    bool checkOnesSegment(string s) {
        int c = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') c = 0;
            else{
                c += 2;
            }
            if(c==2) break;
        }

        return !(c==2);
    }
};