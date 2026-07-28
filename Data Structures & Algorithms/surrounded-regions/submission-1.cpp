class Solution {
private:
    void dfs(int row, int col, vector<vector<pair<int,int>>>& adj, vector<int>& vis, vector<pair<int,int>> &ls, int n)
    {
        int node = row*n + col%n;
        vis[node] = 1;
        ls.push_back({row,col});
        for (auto x : adj[node])
        {
            int cell = x.first*n + x.second%n;
            if (vis[cell] == 0)
                dfs(x.first, x.second, adj, vis, ls, n);
        }
    }
public:
    void MakeGraph(int row,int col,vector<vector<pair<int,int>>>& al,vector<vector<char>>& grid) {
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
            if(!condition && grid[n_ro][n_co]=='O') {
                al[(row*grid[0].size()) + (col%grid[0].size())].push_back({n_ro,n_co});
            }
        }
    }
    
    vector<pair<int,int>> DFS(int row,int col, int n, vector<vector<pair<int,int>>>& adj,vector<int>& vis)
    {
        //int vis[n] = {0};
        
        vector<pair<int,int>> list;
        dfs(row, col, adj, vis, list,n);
        return list;
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int,int>>> al(m*n);
        vector<int>vis(m*n, 0);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='O') {
                    MakeGraph(i,j,al,board);
                }
            }
        }
        vector<vector<pair<int,int>>>ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='O') {
                    if(vis[i*n + j%n]==0)
                    ans.push_back(DFS(i, j,n,al,vis));
                }
            }
        }

        for(auto x : ans) {
            bool flag = false;
            for(auto y : x) {
                int i=y.first;
                int j=y.second;
                if(i==0||j==0||i==m-1||j==n-1) {
                    flag = true;
                }
            }
            if(!flag) {
                for(auto y : x) {
                    board[y.first][y.second]='X';
                }
            }
        }
    }
};
