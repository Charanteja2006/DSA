class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int tot = 0;
        int n = s.size();
        int i = 0;
        while(i<n){
            if(s[i]=='(') cnt++;
            else{
                if(i<n-1 && s[i+1]==')'){
                    if(cnt==0) tot++;
                    else cnt--;
                    i++;
                }
                else{
                    if(cnt==0) tot += 2;
                    else {
                        cnt--;
                        tot++;
                    }
                } 
            }
            i++;
        }

        if(cnt>0) tot += cnt*2;

        return tot;
    }
};