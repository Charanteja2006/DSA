class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        vector<vector<int>> start_sorted = events;
        sort(start_sorted.begin(), start_sorted.end());
        int ans = 0;
        for (auto &e : events)
            ans = max(ans, e[2]);

        int end_max = 0;
        int i = 0;

        for (auto &e : start_sorted) {
            int start = e[0];
            int value = e[2];
            while (i < events.size() && events[i][1] < start) {
                end_max = max(end_max, events[i][2]);
                i++;
            }

            ans = max(ans, value + end_max);
        }

        return ans;
    }
};