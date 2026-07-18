class Solution {
public:
    bool isPalindrome(const string& s) {
        // Compares the first half to the reversed second half
        return equal(s.begin(),s.begin()+s.size()/2,s.rbegin());
    }
    
    string str="";
    vector<string> vec;
    vector<vector<string>> res;
    void backtrack(int index, string s) {
        if(index >= s.size()) {
            res.push_back(vec);
            return;
        }
        //forming partitions of diff lens starting from index
        for(int j=index; j<s.size(); j++) {
            str.assign(s,index,(j-index)+1);//to get substr
            if(isPalindrome(str)) {
                vec.push_back(str);
                backtrack(j+1,s);
                vec.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(0,s);
        return res;
    }
};
