class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> s;
    
        for(auto it:obstacles){
            s.insert({it[0],it[1]});
        }

        vector<pair<int,int>> dire = {
            {0,1},{1,0},{0,-1},{-1,0}
        };

        int maxi = 0;
        int dir = 0;
        int x = 0,y = 0;

        for(auto it:commands){
            if(it==-1) dir = (dir+1)%4;
            
            else if(it==-2) dir = (dir+3)%4;

            else{
                while(it--){
                    int nx = x + dire[dir].first;
                    int ny = y + dire[dir].second;

                    if(s.count({nx,ny})) break;
                    x = nx;
                    y = ny;
                }
                maxi = max(maxi, x*x + y*y);
            }
        }

        return maxi;

     }
};