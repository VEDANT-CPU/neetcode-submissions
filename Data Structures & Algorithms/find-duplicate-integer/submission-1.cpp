class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slo=0;
        int fast=0;
        slo = nums[slo];
        fast = nums[nums[fast]];
        while(slo != fast) {
            slo = nums[slo];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slo != fast) {
            slo = nums[slo];
            fast = nums[fast];
        }
        return slo;
    }
};
