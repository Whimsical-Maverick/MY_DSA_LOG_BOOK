class Solution {
public:
    vector<int> zeroOneBFS(int V, vector<vector<pair<int,int>>> &adj, int src)
    {
        deque<int> dq;
        // vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        dq.push_front(src);
        
        while(!dq.empty())
        {
            int node = dq.front();
            dq.pop_front();
            
            for(auto &[adjNode, wt] : adj[node])
            {
                if(dist[node] + wt < dist[adjNode])
                {
                    dist[adjNode] = dist[node] + wt;
                    
                    if(wt == 0)
                        dq.push_front(adjNode); 
                    else
                        dq.push_back(adjNode);
                }
            }
        }
        
        return dist;
    }
};