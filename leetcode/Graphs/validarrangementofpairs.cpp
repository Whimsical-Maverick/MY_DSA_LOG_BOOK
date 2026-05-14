class Solution {
private:
    void dfs(int &n,int start,vector<vector<int>>&ans,unordered_map<int,vector<int>>&mp)
    {
        if(ans.size()==n)return;
        while(mp[start].size()>0)
        {
            int num = mp[start].back();
            mp[start].pop_back();
            dfs(n,num,ans,mp);
            ans.push_back({start,num});
        }
        return;
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>od;
        unordered_map<int,int>id;
        for(auto el : pairs)
        {
            mp[el[0]].push_back(el[1]);
            od[el[0]]++;
            id[el[1]]++;
        }
        int start = pairs[0][0];
        for(auto el : od)
        {
            if(el.second == id[el.first]+1)
            {
                start = el.first;
            }
        }
        vector<vector<int>>ans;
        int n = pairs.size();
        dfs(n,start,ans,mp);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};