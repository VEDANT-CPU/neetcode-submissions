class Solution {
private:
    void dfs(int node,vector<vector<int>>& al, vector<int>& vis,vector<int>& ls) {
        //if(vis[node]==1) return;
        vis[node]=1;
        ls.push_back(node);
        for(auto x : al[node]) {
            if(!vis[x]) dfs(x,al,vis,ls);
        }
    }
public:
    void MakeGraph(int row,int col,vector<vector<int>>& al,vector<vector<char>>& grid) {
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
            if(!condition && grid[n_ro][n_co]=='1') {
                al[(row*grid[0].size()) + (col%grid[0].size())].push_back((n_ro*grid[0].size()) + (n_co%grid[0].size()));
            }
        }
    }

    vector<int> DFSofGraph(int start, vector<vector<int>>& al, vector<int>& vis) {
        vector<int> ls;
        dfs(start,al,vis,ls);
        return ls;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cells = n*m;
        vector<vector<int>>al(cells);
        vector<int> vis(cells,0);
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]=='1') {
                    MakeGraph(i,j,al,grid);
                }
            }
        }
        
        vector<vector<int>> components;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                int cell = (i*grid[0].size()) + (j%grid[0].size());
                if(grid[i][j]=='1' && vis[cell]==0) {
                    components.push_back(DFSofGraph(cell,al,vis));
                }
            }
        }
        return components.size();
    }
};
