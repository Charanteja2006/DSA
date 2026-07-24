class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0 , r = n - 1;
        int lm = 0 , rm = 0;
        int tot = 0;
        while(l<=r){
            int mini = min(lm,rm);
            if(lm<=rm){
                if(height[l]<mini) tot += mini - height[l];
                lm = max(lm,height[l]);
                l++;
            }
            else{
                if(height[r]<mini) tot += mini - height[r];
                rm = max(rm,height[r]);
                r--;
            }
        }

        return tot;

    }
};