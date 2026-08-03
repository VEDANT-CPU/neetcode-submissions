class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i=0; i<n; i++) {
            pq.push(stones[i]);
        }
        int y=0;
        int x=0;
        while(pq.size() > 1) {
            y = pq.top();
            pq.pop();
            if(!pq.empty()) {x = pq.top(); pq.pop();}
            if(y>x) {y -= x; pq.push(y);}
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
