class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int count = 0;
        if(n==1){
            if(s1==s2) return 0;
            else if(s1[0]=='1') return -1;
            else return 1;
        }

        for(int i=0;i<n-1;i++){
            if(s1[i]==s2[i]){
                continue;
            }
            else if(s1[i]=='0' && s2[i]=='1'){
                s1[i]= '1';
                count++;
            }
            else if(s1[i]=='1' && s2[i]=='0'){
                if(i<n-1 && s1[i+1]=='1'){
                    count++;
                    s1[i+1] = '0';
                    s1[i] = '0';
                }
                else {
                    count+= 2;
                    s1[i] = '0';
                }
            }else return -1;
        }
        if(s1[n-1]=='0'&&s2[n-1]=='1') count++;
        else if(s1[n-1]=='1' && s2[n-1]=='0'){
            count += 2;
        }

        return count;

    }
};