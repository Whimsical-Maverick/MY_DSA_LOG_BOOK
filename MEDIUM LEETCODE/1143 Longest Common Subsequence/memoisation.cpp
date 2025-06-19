class Solution {
public:
    int Solve(string&text1,string&text2,int idx1,int idx2,vector<vector<int>>&dp)
    {
        if(idx1<0 || idx2<0) return 0;
        if(text1[idx1]==text2[idx2]) return dp[idx1][idx2]=1+Solve(text1,text2,idx1-1,idx2-1,dp);
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        return dp[idx1][idx2]=max(Solve(text1,text2,idx1-1,idx2,dp),Solve(text1,text2,idx1,idx2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int idx1=text1.size()-1;
        int idx2=text2.size()-1;
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return Solve(text1,text2,idx1,idx2,dp);
    }
};