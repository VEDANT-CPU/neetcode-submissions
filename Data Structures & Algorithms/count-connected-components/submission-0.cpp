class Solution {
public:
    vector<int> BFS(int start, int n, vector<vector<int>>& adj,vector<int>& vis)
    {
        // vector<int>vis(n);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int x : adj[node])
            {
                if (vis[x] == 0)
                {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return bfs;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) {
            return n;
        }
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<vector<int>> components;
        vector<int>vis(n);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                components.push_back(BFS(i,n, adj,vis));
            }
        }
        return components.size();
    }
};
