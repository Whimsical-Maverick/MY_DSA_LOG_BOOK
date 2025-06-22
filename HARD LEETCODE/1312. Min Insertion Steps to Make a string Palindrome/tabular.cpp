class Solution {
public:
    int minInsertions(string s) 
    {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int idx =s.size()-1;
        int idx2 = s2.size()-1;
        vector<vector<int>>dp(s.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s[i-1]==s2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return s.size()-dp[s.size()][s2.size()];
    }
};