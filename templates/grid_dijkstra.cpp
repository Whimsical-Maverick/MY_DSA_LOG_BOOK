class Solution {
public:
    int dijkstraGrid(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<>
        > pq;
        
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!pq.empty())
        {
            auto [cost, coord] = pq.top();
            pq.pop();
            
            int r = coord.first;
            int c = coord.second;
            
            if(cost > dist[r][c]) continue;
            
            for(auto &d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int new_cost = // MODIFY THIS
                    
                    if(new_cost < dist[nr][nc])
                    {
                        dist[nr][nc] = new_cost;
                        pq.push({new_cost, {nr,nc}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};