void dfs_recursive(int current, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[current] = true;

    // Process current vertex
    std::cout << current << " ";

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            dfs_recursive(neighbor, adj, visited);
        }
    }
}

// Wrapper to handle disconnected graphs
void run_dfs_all(const std::vector<std::vector<int>>& adj) {
    int num_vertices = static_cast<int>(adj.size());
    std::vector<bool> visited(num_vertices, false);

    for (int i = 0; i < num_vertices; ++i) {
        if (!visited[i]) {
            dfs_recursive(i, adj, visited);
        }
    }
}