class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inte, vector<int>& newI) {
        int n = inte.size();
        vector<vector<int>> res;
        int i = 0;

        while(i<n && inte[i][1]<newI[0]){
            res.push_back(inte[i]);
            i++;
        }

        while(i<n && inte[i][0]<=newI[1]){
            newI[0] = min(newI[0],inte[i][0]);
            newI[1] = max(newI[1],inte[i][1]);
            i++;
        }

        res.push_back(newI);

        while(i<n) {
            res.push_back(inte[i]);
            i++;
        }

        return res;
                

    }
};