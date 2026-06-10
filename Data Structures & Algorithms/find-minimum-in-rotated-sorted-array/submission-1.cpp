class Solution {
public:
    int findMin(vector<int> &nums) {
        //nums is Clockwise rotated aka right rotation
        int i = 0;
        int j = nums.size() - 1;
        int mid;
        int min = nums[0];
        while(i <= j) {
            mid = (i+j)/2;
            if(nums[mid] > min) {
                i = mid + 1;
            }else if(nums[mid] < min) {
                min = nums[mid];
                j = mid - 1;
            }else {
                i = mid+1;
            }
        }
        return min;
    }
};
