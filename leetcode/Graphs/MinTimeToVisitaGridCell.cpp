class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) 
    {
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        vector<vector<int>>time(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        time[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<pair<int,int>>dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            auto el = pq.top();
            int tm = el.first;
            int row = el.second.first;
            int col = el.second.second;
            pq.pop();
            if(tm>time[row][col])continue;
            if(row == grid.size()-1 && col == grid[0].size()-1)return tm;
            for(auto ele : dirs)
            {
                int nr = row + ele.first;
                int nc = col + ele.second;
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size())
                {
                    int new_tm = max(tm+1,grid[nr][nc]);
                    if((new_tm-tm)%2==0)new_tm++;
                    if(new_tm < time[nr][nc])
                    {
                        time[nr][nc]=new_tm;
                        pq.push({time[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};