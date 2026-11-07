// Kahn's Algorithm (Topological Sort using BFS)
/* 
Definition & Core Idea:
- A BFS-based approach to find a Topological Ordering of a Directed Acyclic Graph (DAG).
- In-degree: Number of incoming directed edges to a vertex.
- Concept:
  1. Vertices with in-degree == 0 have NO incoming dependencies and can appear first.
  2. Put all vertices with in-degree == 0 into a BFS queue.
  3. Pop a vertex from the queue, add it to the topological order (`ans`).
  4. For each adjacent neighbor, decrement its in-degree by 1 (simulating edge removal).
  5. If any neighbor's in-degree drops to 0, all its prerequisites are met -> push into queue.
  6. Repeat until the queue is empty.

Important Points / Key Features:
1. Valid ONLY on DAGs (Directed Acyclic Graphs).
2. Built-in Cycle Detection:
   - If `ans.size() == V`, the graph is a DAG and `ans` is a valid topological sort.
   - If `ans.size() < V`, there is at least one CYCLE in the graph (nodes in a cycle 
     never reach an in-degree of 0, so they are never added to the queue).
3. Multiple Valid Sorts:
   - Different initial orderings or tie-breaking in the queue produce different valid topological orders.
   - Use `priority_queue` (min-heap) instead of `queue` if lexicographically smallest topological sort is required.
4. Complexity:
   - Time Complexity: O(V + E)
     * O(V + E) to calculate in-degrees.
     * O(V + E) for BFS traversal (each vertex and edge visited once).
   - Space Complexity: O(V) (in-degree array + BFS queue + answer vector).
*/

class Solution {
public:
    // V vertices (0..V-1), adjacency list adj
    vector<int> topoSort(int V, vector<vector<int>>& adj)
    {
        vector<int> inDegree(V, 0);

        // Step 1: Calculate in-degree for every vertex
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
            {
                inDegree[v]++;
            }
        }

        // Step 2: Push all vertices with in-degree 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Step 3: Standard BFS processing
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce in-degree for all adjacent neighbors
            for (int nbr : adj[node])
            {
                inDegree[nbr]--;
                // If in-degree becomes 0, all dependencies are resolved
                if (inDegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        // Step 4 (Optional check): Check for cycle
        // If topo.size() < V, a cycle exists (no valid topological sort possible)
        if (topo.size() < V)
        {
            return {}; // Or handle cycle according to problem requirements
        }

        return topo;
    }
};
