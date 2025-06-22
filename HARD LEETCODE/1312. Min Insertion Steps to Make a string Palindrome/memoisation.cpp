class Solution {
public:
    int Solve(string&s,string&s2,int idx,int idx2,vector<vector<int>>&dp)
    {
        if(idx<0 || idx2<0) return 0;
        if(dp[idx][idx2]!=-1)return dp[idx][idx2];
        if(s[idx]==s2[idx2])return dp[idx][idx2]=1 + Solve(s,s2,idx-1,idx2-1,dp);
        return dp[idx][idx2]=max(Solve(s,s2,idx-1,idx2,dp),Solve(s,s2,idx,idx2-1,dp));
    }
    int minInsertions(string s) 
    {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int idx =s.size()-1;
        int idx2 = s2.size()-1;
        vector<vector<int>>dp(s.size(),vector<int>(s2.size(),-1));
        int result = Solve(s,s2,idx,idx2,dp);
        return s.size()-result;
    }
};