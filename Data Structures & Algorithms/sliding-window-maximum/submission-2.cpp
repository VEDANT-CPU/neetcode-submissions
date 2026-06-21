class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>res;
        //int i=0;No need of i pointer
        //deque acts as the sliding window.
        int j=0;
        while(j<nums.size()) {
            if(!dq.empty() && dq.front()==j-k) {
                dq.pop_front();
            }
            while(!dq.empty() && nums[j]>nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if(j >= k-1) {
                res.push_back(nums[dq.front()]);
            }
            j++;
        }
        return res;
    }
};
