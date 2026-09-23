class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        vector<vector<int>>cost(n+1,vector<int>(2,INT_MAX));
        vector<vector<int>>adj(n+1,vector<int>());
        for(auto el : edges)
        {
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
        }
        int change_time=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,1});
        cost[1][0]=0;
        while(!pq.empty())
        {
            auto ele = pq.top();
            int node = ele.second;
            int Time = ele.first;
            pq.pop();
            if(Time > cost[node][1])continue;
            int new_cost=Time;
            if((Time/change)%2)
            {
                new_cost +=  change - (Time %change);
            }
            new_cost += time;
            for(auto el : adj[node])
            {
                if(new_cost < cost[el][0])
                {
                    cost[el][0] = new_cost;
                    pq.push({new_cost,el});
                }
                else if(new_cost < cost[el][1] && new_cost > cost[el][0])
                {
                    cost[el][1] = new_cost;
                    pq.push({new_cost,el});
                }
            }
        }

        return cost[n][1];
    }
};