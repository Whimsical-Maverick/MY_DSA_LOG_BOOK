class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(auto el : flights)
        {
            adj[el[0]].push_back({el[1],el[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({-1,{0,src}});
        vector<vector<int>>cost(n,vector<int>(k+1,INT_MAX));
        cost[src][0] = 0;
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int stops = el.first;
            int distance = el.second.first;
            int node = el.second.second;
            if(stops+1>k)continue;
            for(auto ele : adj[node])
            {
                int new_cost = distance + ele.second;
                if(new_cost < cost[ele.first][stops+1])
                {
                    cost[ele.first][stops+1] = new_cost;
                    pq.push({stops+1,{new_cost,ele.first}});
                }
            }

        }

        int ans=INT_MAX;
        for(int i=0;i<cost[dst].size();i++)
        {
            if(cost[dst][i]!=INT_MAX)ans = min(ans,cost[dst][i]);
        } 
        return ans==INT_MAX?-1:ans; 
    }
};