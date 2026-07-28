class Solution {
private:
    bool dfsCheck(int node,vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis) {
        vis[node]=1;
        pathvis[node]=1;
        for(auto x : adj[node]) {
            if(!vis[x]) {
                if(dfsCheck(x,adj,vis,pathvis)) return true;
            }else if(pathvis[x]) return true;
        }

        vis[node]=0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> vis(V);
        vector<int> pathvis(V);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
    
    void MakeGraph(int row, vector<vector<int>>& adj,vector<vector<int>>& grid) {
        adj[grid[row][0]].push_back(grid[row][1]);
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        int n = prerequisites[0].size();
        vector<vector<int>> adj(numCourses);

        for(int i=0; i<m; i++) {
            MakeGraph(i,adj,prerequisites);
        }

        //Check for cycles in the graph
        bool ans = isCyclic(numCourses, adj);
        return !ans;
    }
};
