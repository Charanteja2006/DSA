class Solution {
public:
    int minOperations(string s) {
        int c0=0,c1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0' && i%2) c0++;
            else if(s[i]=='1' && i%2) c1++;

            if(s[i]=='1' && i%2==0) c0++;
            else if(s[i]=='0' && i%2==0) c1++; 
        }

        return min(c1,c0);
    }
};