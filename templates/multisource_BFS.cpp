class Solution {
public:
    void multiSourceBFS(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        // vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        
        // Push ALL sources
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(/* source condition */) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty())
        {
            auto [r,c] = q.front(); q.pop();
            
            for(auto &d : dirs)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    // if(dist[r][c] + 1 < dist[nr][nc])
                    // {
                    //     dist[nr][nc] = dist[r][c] + 1;
                    //     q.push({nr,nc});
                    // }
                }
            }
        }
    }
};