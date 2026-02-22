class Solution {
public:
    int binaryGap(int n) {
        int maxi = 0;
        int pos = 0;
        int count = 0;
        while(n>0){
            count++;
            if(n%2){
                if(pos==0) pos = count;
                else{
                    maxi = max(maxi,count - pos);
                    pos = count;
                }
            }
            n /= 2;
        }

        return maxi;
    }
};