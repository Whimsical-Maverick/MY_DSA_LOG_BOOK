class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,vector<pair<int,int>>>mp;
        vector<int>vis(points.size(),0);
        int ans=0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int dist = abs(points[i][0]-points[j][0]) +
                           abs(points[i][1]-points[j][1]);

                mp[i].push_back({j,dist});
                mp[j].push_back({i,dist});
            }
        }
        pq.push({0,0});
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int wt = el.first;
            int node = el.second;
            if(!vis[node])
            {
                vis[node]=1;
                ans+=wt;
                for(auto el : mp[node])
                {
                    if(!vis[el.first])
                    {
                        pq.push({el.second,el.first});
                    }
                }
            }
        }

        return ans;
        
    }
};