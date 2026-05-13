class Solution {
private:
    void DFS(int src,vector<int>&vis,vector<vector<pair<int,int>>>&adj,int&cnt)
    {
        vis[src]=1;
        for(auto el:adj[src])
        {
            if(vis[el.first]!=1)
            {
                cnt+=el.second;
                DFS(el.first,vis,adj,cnt);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(auto element : connections)
        {
            adj[element[0]].push_back({element[1],1});
            adj[element[1]].push_back({element[0],0});
        }

        int cnt=0;
        vector<int>vis(n,0);
        DFS(0,vis,adj,cnt);
        return cnt;
    }
};