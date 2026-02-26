class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        int car = 0;
        int n = s.size();
        for(int i=n-1;i>=1;i--){
            if(s[i]=='0' && car){
                count+=2;
            }
            else if(s[i]=='0' && !car) count++;
            else if(s[i]=='1' && !car){
                count+=2;
                car = 1;
            }
            else{
                count++;
            }
        }
        if(car) count++;
        return count++;
    }
};