class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int hi = nums.size()-1;
        int lo = 0;
        
        while(lo <= hi) {
            index = lo + ((hi-lo)/2);
            if(nums[index] < target) lo = index+1;
            else if(nums[index] > target) hi = index - 1;
            else return index;
        }
        return -1;
    }
};
