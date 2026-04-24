class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),0));
        for(int i=0;i<matrix.size();i++)
        {
            dp[dp.size()-1][i] = matrix[matrix.size()-1][i];
        }
        for(int i=matrix.size()-2;i>=0;i--)
        {
            for(int j=matrix.size()-1;j>=0;j--)
            {
                int left=INT_MAX;
                int center=INT_MAX;
                int right=INT_MAX;
                if(j-1 >= 0) left = dp[i+1][j-1];
                if(j+1 < matrix.size()) right = dp[i+1][j+1];
                center = dp[i+1][j];
                dp[i][j] = matrix[i][j] + min(left,min(right,center));
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};