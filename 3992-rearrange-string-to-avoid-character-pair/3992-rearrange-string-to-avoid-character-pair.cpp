class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int fx = 0,fy = 0;
        for(auto it:s){
            if(x==it) fx++;
            else if(y==it) fy++;
        }

        string res = "";
        for(int i=0;i<fy;i++) res += y;
        for(int i=0;i<fx;i++) res += x;

        for(auto it:s){
            if(it!=x && it!=y) res += it;
        }

        return res;
    }
};