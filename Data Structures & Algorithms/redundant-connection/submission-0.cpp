class Solution {
public:
bool canReach(int curr, int target, vector<vector<int>>& adj,vector<int>& vis,int skipU,int skipV) {
    if(curr == target) return true;
    vis[curr] = 1;
    for(auto neighbors : adj[curr]) {
        if(curr==skipU && neighbors==skipV || curr==skipV && neighbors==skipU) {
            continue;
        }
        
        if((!vis[neighbors]) && canReach(neighbors,target,adj,vis,skipU,skipV)) return true;
    }
    return false;
}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> edge;
        for(int j=n-1; j>=0; j--) {
            int u = edges[j][0];
            int v = edges[j][1];
            vector<int> vis(n+1);
            bool ans=canReach(u,v,adj,vis,u,v);
            if(ans) {
                edge = edges[j];
                break;
            }
        }
        return edge;
    }
};
