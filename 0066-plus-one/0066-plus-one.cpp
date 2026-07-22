class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            if(i==n-1) digits[i] += 1;
            int cur = digits[i] + carry;
            if(cur>=10){
                digits[i] = cur%10;
                carry = cur/10;
            } else{
                digits[i] = cur;
                carry = 0;
            }
        }

        if(carry>0) digits.insert(digits.begin(),carry);

        return digits;
    }
};