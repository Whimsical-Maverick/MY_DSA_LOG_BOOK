class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<vector<int>>cost(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        pq.push({grid[0][0],{0,0}});
        cost[0][0]=grid[0][0];
        vector<pair<int,int>>dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!pq.empty())
        {
            auto el = pq.top();
            int wt = el.first;
            int row = el.second.first;
            int col = el.second.second;
            pq.pop();
            if(wt > cost[row][col])continue;
            if(row==grid.size()-1 && col==grid[0].size()-1)return wt;
            for(auto el : dirs)
            {
                int nr = row + el.first;
                int nc = col + el.second;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size())
                {
                    int new_cost = max(wt,grid[nr][nc]);
                    if(new_cost < cost[nr][nc])
                    {
                        cost[nr][nc] = new_cost;
                        pq.push({cost[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};