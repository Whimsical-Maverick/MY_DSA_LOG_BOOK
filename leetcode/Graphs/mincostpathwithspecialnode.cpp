class Solution {
private:
    int dist(pair<int,int> a, pair<int,int> b)
    {
        return abs(a.first-b.first)+abs(a.second-b.second);
    }
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        
        map<pair<int,int>,int>cost;

        pair<int,int> startPt={start[0],start[1]};
        pair<int,int> targetPt={target[0],target[1]};

        pq.push({0,startPt});
        cost[startPt]=0;
        int ans=dist(startPt,targetPt);
        while(!pq.empty())
        {
            auto [currCost,pos]=pq.top();
            pq.pop();

            if(currCost>cost[pos])
                continue;

            ans=min(ans,
                    currCost+dist(pos,targetPt));

            for(auto &road:specialRoads)
            {
                pair<int,int> roadStart=
                {road[0],road[1]};

                pair<int,int> roadEnd=
                {road[2],road[3]};

                int specialCost=road[4];

                int newCost=
                    currCost
                    + dist(pos,roadStart)
                    + specialCost;

                if(!cost.count(roadEnd)
                   || newCost<cost[roadEnd])
                {
                    cost[roadEnd]=newCost;
                    pq.push({newCost,roadEnd});
                }
            }
        }

        return ans;


    }
};