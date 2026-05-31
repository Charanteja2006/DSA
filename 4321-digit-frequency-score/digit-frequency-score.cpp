class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> mp;

        int score = 0;
        while(n>0){
            mp[n%10]++;
            n /= 10;
        }

        for(auto it:mp){
            score += it.first*it.second;
        }

        return score;
    }
};