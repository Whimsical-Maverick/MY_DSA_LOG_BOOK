class Solution {
private:
    // DFS from node; returns true if a cycle is found in its component.
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis)
    {
        vis[node] = true;
        for(int nbr : adj[node])
        {
            if(!vis[nbr])
            {
                if(dfs(nbr, node, adj, vis)) return true;
            }
            // visited neighbour that isn't the parent => cycle
            else if(nbr != parent) return true;
        }
        return false;
    }
public:
    // V vertices (0..V-1), adjacency list adj
    bool isCycle(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && dfs(i, -1, adj, vis)) return true;
        }
        return false;
    }
};

