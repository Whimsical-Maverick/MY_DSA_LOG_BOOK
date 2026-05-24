class Solution {
private:
    const int MOD = 1e9 + 7;
    int DFS(int node,vector<vector<pair<int,int>>>&adj,vector<int>&cost,vector<int>&dp)
    {
        if(node==1)return 1;
        if(dp[node]!=-1)return dp[node];
        int ways = 0;
        for(auto el : adj[node])
        {
            if(cost[node] < cost[el.first])
            {
               ways += DFS(el.first,adj,cost,dp);
               ways = ways%MOD;
            }
        }
        return dp[node] = ways;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        vector<int>cost(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
        for(auto el : edges)
        {
           adj[el[0]].push_back({el[1],el[2]});
           adj[el[1]].push_back({el[0],el[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,n});
        cost[n] = 0;
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int dist = el.first;
            int node = el.second;
            if(dist>cost[node])continue;
            for(auto ele : adj[node])
            {
                int new_cost = dist + ele.second;
                if(new_cost < cost[ele.first])
                {
                    cost[ele.first] = new_cost;
                    pq.push({new_cost,ele.first});
                }
            }
        }

        vector<int>dp(n+1,-1);

        return DFS(n,adj,cost,dp);
        
    }
};