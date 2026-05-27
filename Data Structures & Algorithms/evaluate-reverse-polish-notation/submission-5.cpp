class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokStack;
        int x;
        int y;
        long long int ans = 0;
        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i]=="+") {
                y = tokStack.top();
                tokStack.pop();
                x = tokStack.top();
                tokStack.pop();
                ans = x + y;
                tokStack.push(ans);
            }else if(tokens[i]=="-") {
                y = tokStack.top();
                tokStack.pop();
                x = tokStack.top();
                tokStack.pop();
                ans = x - y;
                tokStack.push(ans);
            }else if(tokens[i]=="*") {
                y = tokStack.top();
                tokStack.pop();
                x = tokStack.top();
                tokStack.pop();
                ans = x * y;
                tokStack.push(ans);
            }else if(tokens[i]=="/") {
                y = tokStack.top();
                tokStack.pop();
                x = tokStack.top();
                tokStack.pop();
                ans = x / y;
                tokStack.push(ans);
            }else {
                tokStack.push(stoi(tokens[i]));
            }
        }
        if(!tokStack.empty()) ans = tokStack.top();
        return ans;
    }
};
