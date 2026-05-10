class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<int> s;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int j = 1; j * j <= num; j++) {

                if (num % j == 0) {

                    if (s.count(j)) {
                        nums[i] = min(nums[i], j);
                    }

                    if (s.count(num / j)) {
                        nums[i] = min(nums[i], num / j);
                    }
                }
            }

            s.insert(nums[i]);
        }

        return accumulate(nums.begin(), nums.end(), 0LL);
    }
};