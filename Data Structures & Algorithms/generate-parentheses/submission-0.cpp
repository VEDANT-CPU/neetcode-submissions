class Solution {
public:
    string temp="";
    vector<string> res;

    void backtrack(int open,int close,int n) {
        if(open==close && close==n) {
            res.push_back(temp);
            return;
        }

        if(open < n) {
            temp.append(1,'(');
            backtrack(open+1, close, n);
            //If I passed ++open instead than the value of
            //variable in the callee's scope increments too.
            temp.pop_back();
        }

        if(close < open) {
            temp.append(1,')');
            backtrack(open, close+1, n);
            temp.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};
