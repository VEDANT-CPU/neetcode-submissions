class Solution {
private:
    bool BFScheck(int src, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (parent != adjacentNode)
                return true;
        }
    }
    return false;
}

public:
    bool isCycle(int V, vector<vector<int>> &adj)
{
    vector<int> vis(V);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (BFScheck(i, adj, vis))
                return true;
        }
    }
    return false;
}

   vector<int> BFS(int start, int n, vector<vector<int>>& adj,vector<int>& vis)
    {
        // vector<int>vis(n);
        vis[start] = 1;
        queue<int> q;
        q.push(0);
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

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) {
            if(n==1) return true;
            else return false;
        }
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        bool ans = isCycle(n, adj);
        //not having cycle alone is not sufficient
        //there must be only 1 tree, not a forest
        vector<vector<int>> components;
        vector<int>vis(n);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                components.push_back(BFS(i,n, adj,vis));
            }
        }
        if(components.size()>1) ans = true;
        return !ans;
    }
};
