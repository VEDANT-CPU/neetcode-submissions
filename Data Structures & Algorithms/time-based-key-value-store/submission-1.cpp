class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        

    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        //values are inserted in increasing timestamp
        //assumed in the problem
        if(mpp.find(key) == mpp.end()) {
            return "";
        }
        int n = mpp[key].size();
        string str = "";
        for(int i=0; i<n; i++) {
            if(mpp[key][i].first <= timestamp) {
                str = mpp[key][i].second;
            }else break;
        }
        return str;
    }
};
