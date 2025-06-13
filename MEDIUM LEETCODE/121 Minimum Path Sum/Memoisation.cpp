class Solution {
public:
    int Solve(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp)
    {
        if(row>=grid.size() || col>=grid[0].size()) return 1e9;
        if(row==grid.size()-1 && col==grid[0].size()-1)
        {
            return grid[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int down = grid[row][col] + Solve(grid,row+1,col,dp);
        int right = grid[row][col] + Solve(grid,row,col+1,dp);
        return dp[row][col]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int row=0;
        int col=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return Solve(grid,row,col,dp);
    }
};