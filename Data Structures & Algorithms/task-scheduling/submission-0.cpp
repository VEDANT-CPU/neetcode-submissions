class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int j=0; j<tasks.size(); j++) {
            mp[tasks[j]]++;
        }
        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);

        int time=0;
        queue<pair<int,int>>q;
        while(!pq.empty() || !q.empty()) {
            if(!q.empty() && q.front().second==time) {
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()) {
                int top = pq.top();
                if(top) top -= 1;
                pq.pop();
                if(top>0) q.push({top,time+n+1});
            }
            time++;
        }
        return time;
    }
};
