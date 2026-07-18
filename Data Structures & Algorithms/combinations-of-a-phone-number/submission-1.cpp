class Solution {
public:
    map<int, vector<string>>mp = {
        {2,{"a","b","c"}},
        {3,{"d","e","f"}},
        {4,{"g","h","i"}},
        {5,{"j","k","l"}},
        {6,{"m","n","o"}},
        {7,{"p","q","r","s"}},
        {8,{"t","u","v"}},
        {9,{"w","x","y","z"}},
    };
    vector<string>vec;
    string str="";
    void backtrack(int index,string digits) {
        if(index >= digits.size()) {
            if(!str.empty()) vec.push_back(str);
            return;
        }
        for(string& it : mp[digits[index]-'0']) {
            str += it;
            backtrack(index+1, digits);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        backtrack(0,digits);
        return vec;
    }
};
