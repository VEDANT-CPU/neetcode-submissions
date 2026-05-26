class Solution {
public:
    bool isValid(string s) {
        stack<char>inStack;
        vector<char>op_brac={'(','{','['};
        vector<char>cl_brac={')','}',']'};
        for(int i=0; i<s.size(); i++) {
            if(find(op_brac.begin(),op_brac.end(),s[i]) != op_brac.end()) {
                inStack.push(s[i]);
            }else {
                auto it = find(cl_brac.begin(),cl_brac.end(), s[i]);
                if(inStack.empty() || it == cl_brac.end()) return false;
                if(inStack.top()=='(' && *it == ')') inStack.pop();
                else if(inStack.top()=='{' && *it == '}') inStack.pop();
                else if(inStack.top()=='[' && *it == ']') inStack.pop();
                else return false;
            }
        }
        if(!inStack.empty()) return false;
        return true;
    }
};
