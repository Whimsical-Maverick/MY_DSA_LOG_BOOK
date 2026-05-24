class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
    {
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        vector<int>cost(n,INT_MAX);
        cost[0]=0;
        for(auto ele : edges)
        {
            adj[ele[0]].push_back({ele[1],ele[2]});
            adj[ele[1]].push_back({ele[0],ele[2]});
        }
        int num_visitable=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto ele = pq.top();
            int wt = ele.first;
            int node = ele.second;
            pq.pop();
            if(wt > cost[node])continue;
            for(auto el : adj[node])
            {
                int new_dist = wt + el.second + 1;
                if(new_dist < cost[el.first])
                {
                    cost[el.first] = new_dist;
                    pq.push({cost[el.first],el.first});
                }
            }
        }

        for(auto dis : cost)
        {
            if(dis<=maxMoves)num_visitable++;
        }

        for(auto edge : edges)
        {
            int src = edge[0];
            int dest = edge[1];
            int in_bw = edge[2];

            int from_src = max(0,maxMoves - cost[src]);
            int from_dest = max(0,maxMoves - cost[dest]);
            num_visitable+=min(in_bw,from_src+from_dest);
        }

        return num_visitable;
        
    }
};