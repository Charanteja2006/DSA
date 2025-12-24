class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int count = 0;
        for(int i=0;i<capacity.size();i++){
            sum -= capacity[i];
            if(sum<=0) return i+1;
        }
        return capacity.size();
    }
};