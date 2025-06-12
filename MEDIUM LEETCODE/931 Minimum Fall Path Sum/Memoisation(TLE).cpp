class Solution {
public:
    int Solve(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp)
    {
        if(row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size())
        {
            return 1e9;
        }
        if(row==matrix.size()-1) return matrix[row][col];
        if(dp[row][col]!=-1)return dp[row][col];
        int left = matrix[row][col] + Solve(matrix,row+1,col-1,dp);
        int center = matrix[row][col]+Solve(matrix,row+1,col,dp);
        int right = matrix[row][col] + Solve(matrix,row+1,col+1,dp);
        return dp[row][col]=min(left,min(center,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int Min = INT_MAX;
        int row=0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix[0].size();i++)
        {
            Min = min(Min,Solve(matrix,row,i,dp));
        }
        return Min;
    }
};