class Solution {
public:
    int Solve(string&text1,string&text2,int idx1,int idx2,vector<vector<int>>&dp)
    {
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(text1[idx1]==text2[idx2]) return dp[idx1][idx2]=1+Solve(text1,text2,idx1-1,idx2-1,dp);
        return dp[idx1][idx2]=max(Solve(text1,text2,idx1-1,idx2,dp),Solve(text1,text2,idx1,idx2-1,dp));
    }
    int longestPalindromeSubseq(string s) 
    {
        int idx = s.size()-1;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int idx2 = s2.size()-1;
        vector<vector<int>>dp(s.size(),vector<int>(s2.size(),-1));
        return Solve(s,s2,idx,idx2,dp);
    }
};