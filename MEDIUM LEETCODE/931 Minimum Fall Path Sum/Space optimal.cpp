class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        vector<int>dp(matrix.size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            dp[i] = matrix[matrix.size()-1][i];
        }
        for(int i=matrix.size()-2;i>=0;i--)
        {
            vector<int>front = dp;
            for(int j=matrix.size()-1;j>=0;j--)
            {
                int left=INT_MAX;
                int center=INT_MAX;
                int right=INT_MAX;
                if(j-1 >= 0) left = front[j-1];
                if(j+1 < matrix.size()) right = front[j+1];
                center = front[j];
                dp[j] = matrix[i][j] + min(left,min(right,center));
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            ans = min(ans,dp[i]);
        }
        return ans;
    }
};