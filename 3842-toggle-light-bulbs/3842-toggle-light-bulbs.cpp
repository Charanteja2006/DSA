class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mp;
        vector<int> res;
        for(auto it:bulbs) mp[it]++;
        for(auto it:mp){
            if(it.second%2) res.push_back(it.first);
        }

        return res;
    }
};