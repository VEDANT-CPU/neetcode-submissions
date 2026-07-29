class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                if (dfsCheck(x, adj, vis, pathvis))
                    return true;
            }
            else if (pathvis[x])
                return true;
        }

        pathvis[node] = 0;
        return false;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int> &ls)
    {
        vis[node] = 1;
        // ls.push_back(node);
        for (auto x : adj[node])
        {
            if (vis[x] == 0)
                dfs(x, adj, vis, ls);
        }
        ls.push_back(node);
    }

public:
    void MakeGraph(int course, vector<vector<int>>& adj, int prerequisite) {
        adj[course].push_back(prerequisite);
    }
    
    bool isCyclic(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V);
        vector<int> pathvis(V);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathvis) == true)
                    return true;
            }
        }
        return false;
    }

    vector<int> DFS(int start, vector<vector<int>>& adj, vector<int>& vis)
    {
        //vector<int> vis(n);
        
        vector<int> list;
        dfs(start, adj, vis, list);
        return list;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            MakeGraph(prerequisites[i][0],adj, prerequisites[i][1]);
        }

        vector<int>crsorder;
        vector<int>vis(numCourses);
        bool ans = isCyclic(numCourses, adj);
        if(ans) return {};
        else {
            vector<int> temp;
            for(int i=0; i<prerequisites.size(); i++) {
                if(vis[prerequisites[i][0]]==0) {
                    temp=DFS(prerequisites[i][0],adj, vis);
                    crsorder.insert(crsorder.end(),temp.begin(),temp.end());
                }
            }
            if(crsorder.size()<numCourses) {
                unordered_map<int,int>mp;
                for(int j=0; j<crsorder.size(); j++) {
                    mp[crsorder[j]]=1;
                }
                for(int k=0; k<numCourses; k++) {
                    if(mp[k]==0) {
                        crsorder.push_back(k);
                    }
                }
            }
        }
        return crsorder;
    }
};
