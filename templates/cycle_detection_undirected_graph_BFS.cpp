class Solution {
private:
    // BFS from src; returns true if a cycle is found in its component.
    // Each queue entry is {node, parent}.
    bool bfs(int src, vector<vector<int>>& adj, vector<bool>& vis)
    {
        queue<pair<int,int>> q;
        vis[src] = true;
        q.push({src, -1});
        while(!q.empty())
        {
            auto [node, parent] = q.front();
            q.pop();
            for(int nbr : adj[node])
            {
                if(!vis[nbr])
                {
                    vis[nbr] = true;
                    q.push({nbr, node});
                }
                // visited neighbour that isn't the parent => cycle
                else if(nbr != parent) return true;
            }
        }
        return false;
    }
public:
    // V vertices (0..V-1), adjacency list adj
    bool isCycle(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++)// in case of disconnected graph
        {
            if(!vis[i] && bfs(i, adj, vis)) return true;
        }
        return false;
    }
};


// TC -> O(N + 2E) -> Same as BFS for undirected graph(we are traversing every node plus every adj edge);
// SC -> O(N)-> vis + Queue