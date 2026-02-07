class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int ca = 0,count = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a') ca++;
            else if(s[i]=='b' && ca>0){
                count++;
                ca--;
            }
        }

        return count;
    }
};