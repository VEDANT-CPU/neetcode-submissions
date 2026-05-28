class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s1; // mono decreasing stack
        vector<int> result(n);
        // vector<int>suffix(n);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s1.empty() && temperatures[i] > temperatures[s1.top()]) {
                result[s1.top()] = i - s1.top();
                s1.pop();
            }
            s1.push(i);
        }
        return result;
    }
};
