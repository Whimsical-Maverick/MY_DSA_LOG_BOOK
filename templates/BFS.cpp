void BFS(int start,vector<vector<int>>&adj,vector<int>&visited)
{
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto el: adj[node])
        {
            if(visited[el]==0)
            {
                visited[el]=1;
                q.push(el);
            }
        }

    }

    void run_bfs_all(const std::vector<std::vector<int>>& adj) {
    int num_vertices = static_cast<int>(adj.size());
    std::vector<bool> visited(num_vertices, false);

    for (int i = 0; i < num_vertices; ++i) {
        if (!visited[i]) {
            bfs(i, adj, visited);
        }
    }
}
}


// TC -> O(V + E) , V->vertices(nodes) , E->Edges
// SC -> O(V) (O(VE) if adj to be considered)