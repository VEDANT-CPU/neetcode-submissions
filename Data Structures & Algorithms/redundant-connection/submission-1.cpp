class DisjointSet
{
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);

        if (ultp_u == ultp_v)
            return;

        if (rank[ultp_u] > rank[ultp_v])
        {
            parent[ultp_v] = ultp_u;
        }
        else if (rank[ultp_u] < rank[ultp_v])
        {
            parent[ultp_u] = ultp_v;
        }
        else
        {
            parent[ultp_u] = ultp_v;
            rank[ultp_v]++;
        }
    }
};

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> edge;
        vector<vector<int>> adj(n+1);
        DisjointSet ds = DisjointSet(n);

        for(int i=0; i<n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            if(ds.findUPar(edges[i][0]) == ds.findUPar(edges[i][1])) {
                edge = edges[i];
                return edge;
            }
            ds.UnionByRank(edges[i][0],edges[i][1]);
        }
    }
};
