class Solution {
public:
    vector<vector<string>> res;
    set<int>rows;
    set<int>PosDia;
    set<int>NegDia;

    bool Checkcell(int col, int row) {
        if(rows.contains(row)) return false;
        if(PosDia.contains(col+row)) return false;
        if(NegDia.contains(row-col)) return false;

        return true;
    }

    void backtrack(int cnt, int n, vector<string>& vec) {
        if(cnt >= n) {
            res.push_back(vec);
            return;
        }

        for(int i=0; i<n; i++) {
            if(Checkcell(cnt,i)) {
                vec[i][cnt]='Q';
                rows.insert(i);
                PosDia.insert(i+cnt);
                NegDia.insert(i-cnt);
                backtrack(cnt+1,n,vec);
                vec[i][cnt]='.';
                rows.erase(i);
                PosDia.erase(i+cnt);
                NegDia.erase(i-cnt);
            }
            // vec[i][cnt]='.';
            // rows.erase(i);
            // PosDia.erase(i+cnt);
            // NegDia.erase(i-cnt);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>vec;
        string str(n,'.');
        for(int i=0; i<n; i++) {
            vec.push_back(str);
        }
        backtrack(0,n,vec);
        return res;
    }
};
