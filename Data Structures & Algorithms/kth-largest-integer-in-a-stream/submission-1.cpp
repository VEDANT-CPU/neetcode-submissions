class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++) {
            if(pq.size()<k) {
                pq.push(nums[i]);
            }else {
                if(pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(!pq.empty() && val > pq.top()) {
            if(pq.size()==k) pq.pop();
            pq.push(val);
        }else if(pq.empty() || pq.size()<k) {
            pq.push(val);//To handle k > nums.size case
        }
        return pq.top();
    }
};
