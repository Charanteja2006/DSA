class Solution {
public:
    vector<int> nse(vector<int> &v){
        stack<int> s;
        int n = v.size();
        vector<int> res(n,n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && v[s.top()]>=v[i]){
                s.pop();
            }
            if(!s.empty()) res[i] = s.top();
            s.push(i);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns = nse(heights);
        int n = heights.size();
        stack<int> st;
        int maxi = 0;
        for(int i=0;i<n;i++){
            int prev = -1;
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) prev = st.top();
            st.push(i);
            int wid = 0;
            wid += i-prev;
            cout<<wid<<" ";
            wid += ns[i]-i-1;

            maxi = max(maxi,wid*heights[i]);

        }

        return maxi;
    }
};