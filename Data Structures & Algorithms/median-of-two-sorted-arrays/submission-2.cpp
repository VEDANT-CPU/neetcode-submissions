class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int mid = (m+n) / 2;
        int i=0;
        int j=0;
        int cnt=0;
        int b;
        while(i<n && j<m && cnt < mid) {
            if(nums1[i] < nums2[j]) {
                b = nums1[i];
                i++;
            }
            else {
                b = nums2[j];
                j++;
            }
            cnt++;
        }
        
            while(cnt < mid && i < n) {
                b = nums1[i];
                i++;
                cnt++;
            }
            while(cnt < mid && j < m) {
                b = nums2[j];
                j++;
                cnt++;
            }
        
        double a;
        if(i<n && j<m) {
            a = min(nums1[i],nums2[j]);
        }else if(i<n) {
            a = nums1[i];
        }else if(j<m) {
            a = nums2[j];
        }
        if((m+n)%2) return a;
        double median = (a + b) / 2;
        return median;
    }
};
