class Solution {
public:
    vector<vector<int>>memo{100,vector<int>(100,0)};
    vector<vector<int>> dirs = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    int dfs(int i,int j,vector<vector<int>>& matrix) {
        if(i>=matrix.size() || i<0 || j>=matrix[0].size() || j<0) {
            return 0;
        }

        if(memo[i][j] != 0) return memo[i][j];
        int max_path = 0;
        for(int k=0; k<4; k++) {
            int new_x = i + dirs[k][0];
            int new_y = j + dirs[k][1];

            if(new_x>=matrix.size() || new_x<0 || new_y>=matrix[0].size() || new_y<0) {
                max_path = max(max_path,0);
                continue;
            }

            if(matrix[new_x][new_y] > matrix[i][j]) {
                max_path = max(max_path,dfs(new_x,new_y,matrix));
            }
            
        }
        memo[i][j] = 1 + max_path;
        return memo[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans = max(ans,dfs(i,j,matrix));
            }
        }
        return ans;
    }
};
