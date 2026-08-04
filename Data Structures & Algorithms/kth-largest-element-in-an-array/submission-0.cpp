class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int j=0; j<nums.size(); j++) {
            if(pq.size()<k) pq.push(nums[j]);
            else if(pq.size()==k) {
                if(nums[j] > pq.top()) {
                    pq.pop();
                    pq.push(nums[j]);
                }
            }
        }
        return pq.top();
    }
};
