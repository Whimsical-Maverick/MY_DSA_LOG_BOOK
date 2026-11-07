// Topological Sort (DFS Approach)
/* 
Definition:
- A linear ordering of vertices such that for every directed edge u -> v, 
  vertex u appears before vertex v in the ordering.

Important Points:
1. ONLY valid on DAGs (Directed Acyclic Graphs).
   - If the graph has a cycle, no valid topological ordering exists.
   - If the graph is undirected, topological sorting is not defined.
2. Multiple valid topological orderings can exist for the same graph.
3. DFS Intuition (DFS):
   - A node is pushed onto the stack ONLY AFTER all its outgoing neighbors / dependencies 
     are fully processed.
   - Popping from the stack at the end reverses the finish times, ensuring 'u' appears before 'v'.
4. Cycle Detection Caveat:
   - This standard DFS implementation ASSUMES the graph is already a DAG.
   - If the graph might contain cycles, you should detect cycles using visited + pathVis arrays,
     or use Kahn's Algorithm (BFS) which detects cycles automatically.
5. Complexity:
   - Time Complexity: O(V + E) (visits each vertex and traverses each edge once)
   - Space Complexity: O(V) (visited array, recursion stack, and result stack)
*/

class Solution {
private:
    // DFS helper: visits all descendants and pushes node to stack upon completion
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st)
    {
        vis[node] = true;
        for(int nbr : adj[node])
        {
            if(!vis[nbr])
            {
                dfs(nbr, adj, vis, st);
            }
        }
        st.push(node); // Push to stack only after all outgoing neighbors are processed
    }

public:
    // V vertices (0..V-1), adjacency list adj
    vector<int> topoSort(int V, vector<vector<int>>& adj)
    {
        vector<bool> vis(V, false);
        stack<int> st;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis, st);
            }
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
