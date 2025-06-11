class Solution {
public:
    int Solve(vector<vector<int>>&obstacleGrid,int start,int end,int&row,int&col,vector<vector<int>>&dp)
    {
        if(start>row || end>col) return 0;
        if(obstacleGrid[start][end]==1) return 0;
        if(start==row && end==col) return 1;
        if(dp[start][end]!=-1) return dp[start][end];
        return dp[start][end] = Solve(obstacleGrid,start+1,end,row,col,dp) + Solve(obstacleGrid,start,end+1,row,col,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int row = obstacleGrid.size()-1;
        int col = obstacleGrid[0].size()-1;
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        int start=0;
        int end=0;
        return Solve(obstacleGrid,start,end,row,col,dp);
    }
};
int main()
{
    vector<vector<int>>obstacleGrid;
    // initialize this first
    Solution obj1;
    return obj1.uniquePathsWithObstacles(obstacleGrid);
}