class MedianFinder {
private:
    priority_queue<int>pq1;//max heap
    priority_queue<int,vector<int>,greater<int>>pq2;//min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty() || num <= pq1.top()) {
            pq1.push(num);
        }else {
            pq2.push(num);
        }
        while(abs((int)pq1.size()-(int)pq2.size())>1) {
            if(pq1.size() > pq2.size()+1) {
                pq2.push(pq1.top());
                pq1.pop();
            }else if(pq2.size() > pq1.size()+1) {
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()) {
            return (double) (pq1.top() + pq2.top()) / 2.0;
        }else if(pq1.size() > pq2.size()) {
            return (double) pq1.top();
        }else {
            return (double) pq2.top();
        }
        return 0.0;
    }
};
