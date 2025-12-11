class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> xmin(n+1,n+1);
        vector<int> ymin(n+1,n+1);
        vector<int> xmax(n+1,0);
        vector<int> ymax(n+1,0);
        for(auto b:buildings){
            int x = b[0];
            int y = b[1];
            xmin[y] = min(xmin[y],x);
            ymin[x] = min(ymin[x],y);
            xmax[y] = max(xmax[y],x);
            ymax[x] = max(ymax[x],y);
        }
        int cnt = 0;
        for(auto b:buildings){
            int x = b[0];
            int y = b[1];
            if(x>xmin[y] && x<xmax[y] && y>ymin[x] && y<ymax[x]) cnt++;
        }
        return cnt;
    }
};