class Solution {
private:
    void dfs(int start, vector<vector<int>>& al, vector<int>& vis,vector<int>& ls) {
        
        vis[start] = 1;
        ls.push_back(start);
        for(auto x : al[start]) {
            if(vis[x]==0) dfs(x,al,vis,ls);
        }
    }
public:
    void MakeGraph(int row,int col,vector<vector<int>>& al,vector<vector<int>>& grid) {
        vector<vector<int>> directions = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        for(auto d : directions) {
            int n_ro = row+d[0];
            int n_co = col+d[1];
            bool condition = (n_ro<0 || n_ro>=grid.size() || n_co<0 || n_co>=grid[0].size());
            if(!condition && grid[n_ro][n_co]==1) {
                al[(row*grid[0].size()) + (col%grid[0].size())].push_back((n_ro*grid[0].size()) + (n_co%grid[0].size()));
            }
        }
    }
    int DFSofGraph(int start, vector<vector<int>>& al, vector<int>& vis) {
        vector<int> ls;
        dfs(start,al,vis,ls);
        return ls.size();
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cells = n*m;
        vector<vector<int>> al(cells);
        //forming Adj List
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    MakeGraph(i,j,al,grid);
                }
            }
        }
        //getting connected components
        vector<int>vis(cells);
        
        int res=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int cell = (i*grid[0].size()) + (j%grid[0].size());
                if(grid[i][j]==1 && vis[cell]==0) {
                    res = max(res,DFSofGraph(cell, al, vis));
                }
            }
        }
        return res;
    }
};
