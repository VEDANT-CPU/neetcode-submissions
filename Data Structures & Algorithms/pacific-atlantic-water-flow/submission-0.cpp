class Solution {
public:
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<int>vis(n*m,0);
        vector<vector<int>> res;
        queue<pair<int, int>> q;
        vector<pair<int,int>>atlantic;
        vector<pair<int,int>>pacific;

        // Step 1: Push all boundary cells into the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i==0 || j==0)
                {//for pacific ocean
                    q.push({i, j});
                    pacific.push_back({i,j});
                    vis[i*n + j%n] = 1;
                }
            }
        }

        // Direction vectors for moving Up, Down, Left, Right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Multi-source BFS

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int nr = r + dr;
                int nc = c + dc;

                // If out of bounds, or it's a wall (-1), or already visited/closer chest found
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || heights[nr][nc] < heights[r][c])
                {
                    continue;
                }
                if(vis[nr*n + nc%n]==0) {
                    pacific.push_back({nr,nc});
                    q.push({nr, nc});
                    vis[nr*n + nc%n] = 1;
                }
            }
        }
        //Reset visited vector
        vis.assign(vis.size(), 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i==m-1 || j==n-1)
                {//for atlantic ocean
                    q.push({i, j});
                    atlantic.push_back({i,j});
                    vis[i*n + j%n] = 1;
                }
            }
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions)
            {
                int nr = r + dr;
                int nc = c + dc;

                // If out of bounds, or it's a wall (-1), or already visited/closer chest found
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || heights[nr][nc] < heights[r][c])
                {
                    continue;
                }

                if(vis[nr*n + nc%n]==0) {
                    atlantic.push_back({nr,nc});
                    q.push({nr, nc});
                    vis[nr*n + nc%n] = 1;
                }
            }
        }

        set<pair<int,int>> mySet;
        for(auto x : pacific) {
            mySet.insert(x);
        }
        for(auto x : atlantic) {
            if(mySet.contains(x)) {
                res.push_back({x.first,x.second});
            }
        }

        return res;
    }
};
