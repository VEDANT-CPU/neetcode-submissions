class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>tempStack;
        stack<int>s2;
        vector<int>result(n);
        //vector<int>suffix(n);
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) result[i] = 0;
            else {
                while(!tempStack.empty() && temperatures[i] >= tempStack.top()) {
                    result[i]++;
                    s2.push(tempStack.top());
                    if(!tempStack.empty()) tempStack.pop();
                }
                if(tempStack.empty()) {
                    result[i] = 0;
                    
                }else {
                    if(tempStack.top() > temperatures[i] ) result[i]++;
                }
                
                    while(!s2.empty()) {
                        tempStack.push(s2.top());
                        s2.pop();
                    }
                    
                
            }
            tempStack.push(temperatures[i]);
        }
        return result;
    }
};
