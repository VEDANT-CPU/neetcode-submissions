class Solution {
public:
    
    string encode(vector<string>& strs) {
        string msg="";
        for(int i=0; i<strs.size(); i++) {
            int len = strs[i].size();
            string str_len = to_string(len);
            msg.append(str_len);
            msg.append("#");
            msg.append(strs[i]);
        }
        return msg;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        string str_len;
        bool flag = false;
        int j=0;
        while(j<s.size()) {
            if((!flag) && s[j]!='#') {str_len.append(1, s[j]); j++;}
            else if((!flag) && s[j]=='#') {flag = true; j++;}

            if(flag) {
                string decod_ele;
                int len = stoi(str_len);
                while(len --) {
                    decod_ele.push_back(s[j]);
                    j++;
                }
                decoded.push_back(decod_ele);
                flag = false;
                str_len.clear();
            }
            
        }
        return decoded;
    }
};
