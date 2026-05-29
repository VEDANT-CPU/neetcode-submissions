class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        //sorting positions and corresponding speeds in nlogn time
        vector<pair<int,int>>vec;
        for(int i=0; i<n; i++) {
            vec.push_back({position[i],speed[i]});
        }
        make_heap(vec.begin(), vec.end());//O(n) time
        sort_heap(vec.begin(), vec.end());//O(nlogn) time
        for(int j=0; j<n; j++) {
            position[j] = vec[j].first;
            speed[j] = vec[j].second;
        }
        int fleets = n;
        stack<float>s1;//mono decreasing stack
        for(int i=0; i<n; i++) {
            while(!s1.empty() && (target-position[i])/(float)speed[i] >= s1.top()) {
                fleets--;
                s1.pop();
            }
            s1.push((target-position[i])/(float)speed[i]);
        }
        return fleets;
    }
};
