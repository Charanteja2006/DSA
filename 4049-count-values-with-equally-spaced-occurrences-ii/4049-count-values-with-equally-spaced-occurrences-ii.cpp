class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int count = 0;
        for(auto it:mp){
            vector<int> v = it.second;
            int m = v.size();
            if(m < 3) continue;
            bool f = true;
            for(int i = 1;i<m-1;i++){
                if(v[i] - v[i-1] != v[i+1] - v[i]){
                    f = false;
                    break;
                }
            }

            if(f) count++;
        }

        return count;
    }
};