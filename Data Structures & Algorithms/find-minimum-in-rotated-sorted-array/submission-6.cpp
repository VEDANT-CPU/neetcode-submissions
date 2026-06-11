class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;
        int minima = nums[i];
        int mid;
        while(i <= j) {
            if(nums[i] < nums[j]) {
                minima = min(minima,nums[i]);
                break;
            }
            mid = (i+j)/2;
            if(minima > nums[mid]) minima = nums[mid];
            if(nums[mid] >= nums[i]) {
                
                i = mid+1;
            }else {
                
                j = mid - 1;
            }
        }
        return minima;
    }
};
