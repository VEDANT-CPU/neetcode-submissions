class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh_oranges = 0;
        
        // Step 1: Collect initial rotten oranges and count fresh ones
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        
        // If there are no fresh oranges to begin with, 0 minutes are needed
        if(fresh_oranges == 0) return 0;
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;
        
        // Step 2: Level-by-level BFS
        while(!q.empty()) {
            int size = q.size();
            bool rotted_any_this_minute = false;
            
            // Process all oranges currently at the current minute layer
            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for(auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1) {
                        continue;
                    }
                    
                    grid[nr][nc] = 2; // Make it rotten
                    fresh_oranges--;
                    rotted_any_this_minute = true;
                    q.push({nr, nc});
                }
            }
            
            // Only increment time if this round actually spread the rot
            if(rotted_any_this_minute) {
                minutes++;
            }
        }

        // Step 3: Check if any fresh oranges couldn't be reached
        return (fresh_oranges == 0) ? minutes : -1;
    }
};