class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1, mp2, mp;
        int n = nums1.size();

        for(int i = 0; i < n; i++){
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
            mp[nums1[i]]++;
            mp[nums2[i]]++;
        }

        for(auto &it : mp){
            if(it.second % 2) return -1;
        }

        int cost = 0;

        for(auto &it : mp){
            int x = it.first;
            cost += abs(mp1[x] - mp2[x]) / 2;
        }

        return cost / 2;
    }
};