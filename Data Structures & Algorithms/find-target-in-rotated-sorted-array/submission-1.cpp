class Solution {
public:
    int findMin(vector<int>& nums) {
        //nums is Clockwise rotated aka right rotation
        int i = 0;
        int j = nums.size() - 1;
        int mid;
        int min = 0;
        while(i <= j) {
            mid = (i+j)/2;
            if(nums[mid] > nums[min]) {
                i = mid + 1;
            }else if(nums[mid] < nums[min]) {
                min = mid;
                j = mid - 1;
            }else {
                i = mid+1;
            }
        }
        return min;
    }
    
    int binarySearch(int it1, int it2, vector<int>& nums, int target) {
        int i=it1;
        int j = it2;
        int mid;
        while(i <= j) {
            mid = (i+j)/2;
            if(nums[mid] < target) {
                i = mid + 1;
            }else if(nums[mid] > target) {
                j = mid - 1;
            }else {
                break;
            }
        }
        if(nums[mid] != target) {
            mid = -1;
        }
        return mid;
    }

    int search(vector<int>& nums, int target) {
        int cut = findMin(nums);
        int s1 = binarySearch(0, cut-1, nums, target);
        int s2 = binarySearch(cut, nums.size()-1, nums, target);
        if(s1 != -1) return s1;
        else return s2;
        
    }
};
