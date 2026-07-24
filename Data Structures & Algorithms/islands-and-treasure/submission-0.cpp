class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return;
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        
        // Step 1: Push all treasure chests (0) into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        // Direction vectors for moving Up, Down, Left, Right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                
                // If out of bounds, or it's a wall (-1), or already visited/closer chest found
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != INT_MAX) {
                    continue;
                }
                
                // Update distance (parent distance + 1)
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};