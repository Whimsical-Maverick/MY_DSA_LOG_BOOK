class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        vector<int>cost(n,INT_MAX);
        cost[0]=0;
        cost[firstPerson]=0;
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(auto el : meetings)
        {
            adj[el[0]].push_back({el[1],el[2]});
            adj[el[1]].push_back({el[0],el[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(!pq.empty())
        {
            auto el = pq.top();
            int curr_time = el.first;
            int sender = el.second;
            pq.pop();
            if(curr_time > cost[sender])continue;
            for(auto ele : adj[sender])
            {
                if(curr_time <= ele.second && curr_time<cost[ele.first])
                {
                    cost[ele.first] = ele.second;
                    pq.push({cost[ele.first],ele.first});
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<cost.size();i++)
        {
            if(cost[i]!=INT_MAX)ans.push_back(i);
        }

        return ans;
    }
};