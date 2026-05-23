class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty())
        {
            auto el = q.front();
            int row = el.first;
            int col = el.second;
            q.pop();
            for(auto ele : dirs)
            {
                int nr = ele[0] + row;
                int nc = ele[1] + col;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size())
                {
                    if(dist[nr][nc]==INT_MAX || dist[nr][nc] > dist[row][col] + 1)
                    {
                        dist[nr][nc] = dist[row][col]+1;
                        q.push({nr,nc});
                    }

                }
            }
        }
        
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>SF(grid.size(),vector<int>(grid[0].size(),INT_MIN));
        pq.push({dist[0][0],{0,0}});
        SF[0][0]=dist[0][0];
        while(!pq.empty())
        {
            auto el = pq.top();
            int sf = el.first;
            int row = el.second.first;
            int col = el.second.second;
            pq.pop();
            if(sf < SF[row][col])continue;
            if(row==grid.size()-1 && col==grid[0].size()-1)return sf;
            for(auto ele : dirs)
            {
                int nr = ele[0] + row;
                int nc = ele[1] + col;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size())
                {
                    int new_sf = min(sf,dist[nr][nc]);
                    if(new_sf > SF[nr][nc])
                    {
                        SF[nr][nc] = new_sf;
                        pq.push({SF[nr][nc],{nr,nc}});
                    }

                }
            }
        }
        return -1;
    }
};