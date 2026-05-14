class Solution {
private:
    void DFS(string src,vector<string>&ans,unordered_map<string,multiset<string>>&mp)
    {
        while(!mp[src].empty())
        {
            auto it = mp[src].begin();
            string neighbor = *it;
            mp[src].erase(it);
            DFS(neighbor,ans,mp);
        }
        ans.push_back(src);
        return;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        unordered_map<string,multiset<string>>mp;
        for(auto el : tickets)
        {
            mp[el[0]].insert(el[1]);
        }

        vector<string>ans;
        DFS("JFK",ans,mp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};