class Solution {
private:
    // DFS from node; returns true if a cycle is found in its component.
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>&vis,vector<bool>& pathVis)
    {
        vis[node]=true;
        pathVis[node] = true;
        for(int nbr : adj[node])
        {
            if(!vis[nbr])
            {
                vis[nbr]=1;
                if(dfs(nbr, adj, vis,pathVis)) return true;
            }
            else if(pathVis[nbr]==true) return true;
        }
        pathVis[node] = false;
        return false;
    }
public:
    // V vertices (0..V-1), adjacency list adj
    bool isCycle(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis(V, false);
        vector<bool> pathVis(V,false);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && dfs(i, adj, vis,pathVis))
            {
                return true;
            }
        }
        return false;
    }
};

