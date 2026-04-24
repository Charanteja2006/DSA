class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int c1 = 0,c2 = 0,c3 = 0;

        for(auto it:moves){
            if(it=='L') c1++;
            else if(it=='R') c2++;
            else c3++;
        }

        return abs(c1-c2) + c3;
    }
};