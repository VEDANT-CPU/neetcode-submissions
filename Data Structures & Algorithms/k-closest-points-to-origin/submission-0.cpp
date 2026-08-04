class Solution {
public:
    static double dist(const vector<int>& p1) {
        double diff1 = abs(p1[0]-0);
        double diff2 = abs(p1[1]-0);

        double t1 = diff1 * diff1;
        double t2 = diff2 * diff2;

        return sqrt(t1 + t2);
    }

    struct CustomCompare {
        
        bool operator()(const vector<int>& a,const vector<int>& b) const{
            return Solution::dist(a) < Solution::dist(b);
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,CustomCompare> pq;
        for(auto x : points) {
            if(pq.size() < k) {
                pq.push(x);
            }else if(pq.size() == k) {
                if(dist(x) < dist(pq.top())) {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
