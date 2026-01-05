class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int count = 0;
        long long sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j]<0) count++;
                mini = min(mini,abs(matrix[i][j]));
            }
        }
        if(count%2) return (sum - 2*1LL*mini);
        return sum;
    }
};