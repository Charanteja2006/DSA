class Solution {
public:
    int bitwiseComplement(int n) {
        int maxi = 0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)) maxi = i;
        }
        return (((1<<(maxi+1)) - 1)^n);
    }
};