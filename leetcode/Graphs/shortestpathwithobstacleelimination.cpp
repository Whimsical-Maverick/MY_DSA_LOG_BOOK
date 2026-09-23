class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        vector<vector<vector<bool>>>vis(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(k+1,false)));
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>>q;
        q.push({0,0,0,0});
        vis[0][0][0] = 1;
        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            int obstacles = el[0];
            int steps = el[1];
            int row = el[2];
            int col = el[3];
            if(row==grid.size()-1 && col==grid[0].size()-1)return steps;
            for(auto dir : dirs)
            {
                int nr = row + dir[0];
                int nc = col + dir[1];
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size())
                {
                    if(grid[nr][nc]==1)
                    {
                       //want to remove
                       if(obstacles+1<=k && !vis[nr][nc][obstacles+1])
                       {
                          int new_cost = steps+1;
                          vis[nr][nc][obstacles+1] = true;
                          q.push({obstacles+1,new_cost,nr,nc});
                       }
                    }
                    else if(!vis[nr][nc][obstacles])
                    {
                        int new_cost = steps+1;
                        vis[nr][nc][obstacles] = true;
                        q.push({obstacles,new_cost,nr,nc});
                    }
                }
            }
        }

        return -1;
    }
};