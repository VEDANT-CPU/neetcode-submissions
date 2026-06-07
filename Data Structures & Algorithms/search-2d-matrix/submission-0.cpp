class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++) {
            if(target>=matrix[i][0] && target<=matrix[i][n-1]) {
                int lo = 0;
                int hi = n-1;
                int mid;
                while(lo <= hi) {
                    mid = lo + ((hi-lo)/2);
                    if(matrix[i][mid] > target) hi = mid-1;
                    else if(matrix[i][mid] < target) lo = mid+1;
                    else return true;
                }
            }
        }
        return false;
    }
};
