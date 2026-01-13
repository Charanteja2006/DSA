class Solution {
public:
    double calculateAreaBelow(const vector<vector<int>>& squares, double y) {
        double area = 0.0;
        for (const auto& square : squares) {
            int x_i = square[0];
            int y_i = square[1];
            int l_i = square[2];
            if (y_i + l_i <= y) {
                area += (long long)l_i * l_i; 
            } else if (y_i < y) {
                area += (y - y_i) * l_i;
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        for (const auto& square : squares) {
            int l_i = square[2];
            totalArea += (long long)l_i * l_i; 
        }
    
        double low = 0.0, high = 2e9;
        double precision = 1e-5;
        while (high - low > precision) {
            double mid = (low + high) / 2;
            double areaBelow = calculateAreaBelow(squares, mid);
            if (areaBelow < totalArea / 2) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return (low + high) / 2;
    }
};