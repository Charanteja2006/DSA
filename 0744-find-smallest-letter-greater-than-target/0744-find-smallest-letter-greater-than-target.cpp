class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0 , r = n-1;
        char c = letters[0];
        while(l<=r){
            int mid = (l+r)/2;
            if(letters[mid]>target){
                c = letters[mid];
                r = mid-1;
            } else{
                l = mid+1;
            }
        }

        return c;
    }
};