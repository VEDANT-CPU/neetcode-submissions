class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        int water_area = 0;
        //You seek gretest in the left part & in right part
        //excluding the current element.
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) suffix[i] = 0;
            else {
                suffix[i] = max(suffix[i+1],height[i+1]);
            }
        }

        for(int i=0; i<n; i++) {
            if(i==0) prefix[i] = 0;
            else {
                prefix[i] = max(prefix[i-1], height[i-1]);
            }
        }

        for(int k=0; k<n; k++) {
            if(min(prefix[k],suffix[k]) > height[k]) {
                water_area += min(prefix[k],suffix[k]) - height[k];
            }
        }
        return water_area;
    }
};
