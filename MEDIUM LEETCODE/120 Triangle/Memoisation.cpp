class Solution {
public:
    int Solve(vector<vector<int>>&triangle,int row,int col,vector<vector<int>>&dp)
    {
        if(row == triangle.size()-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int left = Solve(triangle,row+1,col,dp);
        int right = Solve(triangle,row+1,col+1,dp);
        return dp[row][col]=triangle[row][col] +min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int Min =INT_MAX;
        int row=0;
        int col=0;
        int sum=0;
        vector<vector<int>>dp;
        for (int i = 0; i < triangle.size(); ++i) {
            dp.push_back(vector<int>(triangle[i].size(), -1));
        }
        return Solve(triangle,row,col,dp);
    }
};
int main()
{
    vector<vector<int>>triangle;
    // initialise the vector
    Solution obj1;
    return obj1.minimumTotal(triangle);
}