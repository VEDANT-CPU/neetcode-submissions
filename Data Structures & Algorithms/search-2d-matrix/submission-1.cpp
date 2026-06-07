class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = m*n - 1;
        int mid;
        while(lo <= hi) {
            mid = (hi+lo) / 2;
            if(matrix[mid/n][mid%n] > target) hi = mid-1;
            else if(matrix[mid/n][mid%n] < target) lo = mid+1;
            else return true;
        }
        return false;
    }
};
