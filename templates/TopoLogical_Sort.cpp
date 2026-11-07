//Topological Sort
/* Eg -> 5 4 2 3 1 0 
         5 -> 4
         4 -> 0 
         5 -> 2
         2 -> 3
         3 -> 1
         4 -> 1
         
If there is an edge between u->v
u appears before v, for all u and v
its only possible on a DAG(Directed acyclic Graph)
*/

class Solution {
private:
    // DFS from node; returns true if a cycle is found in its component.
    void dfs(int node, vector<vector<int>>& adj, vector<bool>&vis,stack<int>&st)
    {
        vis[node]=true;
        for(int nbr : adj[node])
        {
            if(!vis[nbr])
            {
                vis[nbr]=1;
                dfs(nbr, adj, vis, st);
            }
        }
        st.push(node);
        return;
    }
public:
    // V vertices (0..V-1), adjacency list adj
    vector<int> isCycle(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis(V, false);
        stack<int>st;
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])dfs(i,adj,vis,st);
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};