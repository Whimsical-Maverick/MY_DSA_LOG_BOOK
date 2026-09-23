class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src)
    {
        vector<int> dist(V, INT_MAX);
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            
            if(d > dist[node]) continue; // 🔥 must
            
            for(auto &[adjNode, wt] : adj[node])
            {
                int new_dist = d + wt; // 🔁 MODIFY HERE if needed
                
                if(new_dist < dist[adjNode])
                {
                    dist[adjNode] = new_dist;
                    pq.push({new_dist, adjNode});
                }
            }
        }
        
        return dist;
    }
};