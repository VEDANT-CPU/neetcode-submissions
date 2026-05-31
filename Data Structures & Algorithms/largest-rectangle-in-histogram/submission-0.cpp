class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s1;//Mono increasing stack.
        for(int i=0; i<n; i++) {
            while(!s1.empty() && heights[i] < heights[s1.top()]) {
                int index = s1.top();
                s1.pop();
                right[index] = i;
            }
            s1.push(i);
        }
        while(!s1.empty()) {
            int index = s1.top();
            s1.pop();
            right[index] = n;
        }
        
        for(int i=n-1; i>=0; i--) {
            while(!s1.empty() && heights[i] < heights[s1.top()]) {
                int index = s1.top();
                s1.pop();
                left[index] = i;
            }
            s1.push(i);
        }
        while(!s1.empty()) {
            int index = s1.top();
            s1.pop();
            left[index] = -1;
        }
        int max_rect=0;
        for(int j=0; j<n; j++) {
            int width = right[j]-left[j] - 1;
            if(max_rect < heights[j]*width) max_rect = heights[j]*width;
        }
        return max_rect;
    }
};
