class Solution {
public:
    struct Compare {
        bool operator()(pair<int,int>& p1,pair<int,int>& p2) {
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        
        for(int x : nums) {
            mpp[x]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>minpq;
        for(auto x : mpp) {
            if(minpq.size() < k){
                minpq.push({x.first,x.second});
            }else {
                if(x.second >= minpq.top().second) {
                    minpq.pop();
                    minpq.push({x.first,x.second});
                }
            }
        }
        vector<int>res;
        while(!minpq.empty()) {
            res.push_back(minpq.top().first);
            minpq.pop();
        }
        return res;
    }
};
