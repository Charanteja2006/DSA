class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int req = (n + m + 1)/2;
        int l = 0,r = n;
        while(l<=r){
            int m1 = (l+r)/2;
            int m2 = req - m1;
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;
            if(m1-1 >= 0) l1 = nums1[m1-1];
            if(m2-1 >= 0) l2 = nums2[m2-1];
            if(m1<n) r1 = nums1[m1];
            if(m2<m) r2 = nums2[m2];

            if(l1<=r2 && l2<=r1){
                if((n+m)&1) return (double)(max(l1,l2));
                else return (double)((max(l1,l2)*1.0 + min(r1,r2)*1.0)/2);
            }

            else if(l1>r2) r = m1-1;
            else l = m1+1;
        }

        return 0;
    }
};