class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        vector<vector<int>>cost(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{0,0}});
        vector<pair<int,int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty())
        {
            auto el = pq.top();
            int wt = el.first;
            int row = el.second.first;
            int col = el.second.second;
            pq.pop();
            if(wt>cost[row][col])continue;
            if(row==heights.size()-1 && col==heights[0].size()-1)return wt;
            for(auto el : dirs)
            {
                int nr = row+el.first;
                int nc = col+el.second;
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size())
                {
                    int new_cost = max(wt,abs(heights[nr][nc] - heights[row][col]));
                    if(new_cost < cost[nr][nc])
                    {
                        cost[nr][nc] = new_cost;
                        pq.push({new_cost,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};