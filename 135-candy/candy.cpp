class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();

        int tot = 1;
        int i = 1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;
                tot += 1;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak += 1;
                tot += peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                tot += down;
                down += 1;
                i++;
            }
            if(down>peak) tot += down-peak;
        }
        return tot;
        
    }
};