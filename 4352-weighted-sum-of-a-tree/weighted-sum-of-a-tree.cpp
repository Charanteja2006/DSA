class Solution {
public:
    int finddepth(int i,vector<int>& dept,vector<int>& par){
        if(i==0 || dept[i]!=-1) return dept[i];
        
        return dept[i] = 1 + finddepth(par[i],dept,par);

    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<int> dept(n,-1);
        dept[0] = 1;
        int maxi = 1;
        for(int i=1;i<n;i++) {
            if(dept[i]==-1) finddepth(i,dept,parent);
            maxi = max(maxi,dept[i]);
        }

        long long res = 0;
        for(int i=0;i<n;i++) res += 1LL*nums[i]*(maxi - dept[i] + 1);

        return res;
    }
};