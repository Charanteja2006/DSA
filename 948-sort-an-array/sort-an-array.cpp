class Solution {
public:
    int qsort(vector<int> &v, int l, int r) {
        int piv = v[l];
        int low = l + 1;
        int high = r;

        while (low <= high) {

            while (low <= r && v[low] <= piv)
                low++;

            while (high >= l + 1 && v[high] >= piv)
                high--;

            if (low < high)
                swap(v[low], v[high]);
        }

        swap(v[l], v[high]);

        return high;
    }

    void qs(vector<int> &v, int l, int r) {
        if (l < r) {
            int pind = qsort(v, l, r);

            qs(v, l, pind - 1);
            qs(v, pind + 1, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};