class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int max_area = 0;
        while(l < r) {
            int h = min(heights[l],heights[r]);
            int width = r - l;
            int a1 = min(heights[l+1],heights[r])*(width-1);
            int a2 = min(heights[l],heights[r-1])*(width-1);
            if(max_area < h * width) max_area = h * width;
            if(heights[l] < heights[r]) l++;
            else r--;
            
        }
        return max_area;
    }
};
