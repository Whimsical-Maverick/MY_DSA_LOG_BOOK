class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int target_mask = (1<<graph.size())-1;
        vector<vector<int>>visited(graph.size()+1,vector<int>(target_mask+1,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<graph.size();i++)
        {
            int mask=(1<<i);
            q.push({0,{mask,i}});
            visited[i][mask]=1;
        }
        while(!q.empty())
        {
            auto el = q.front();
            int node = el.second.second;
            int mask = el.second.first;
            int steps = el.first;
            q.pop();
            if(mask==target_mask)return steps;
            for(auto el : graph[node])
            {
                int new_mask = mask;
                new_mask = new_mask|(1<<el);
                if(!visited[el][new_mask])
                {
                    visited[el][new_mask]=1;
                    q.push({steps+1,{new_mask,el}});
                }
            }
        }
        return -1;
    }
};