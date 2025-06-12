class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int>dp(triangle[triangle.size()-1].size(),0);
        for(int i=0;i<dp.size();i++)
        {
            dp[i] = triangle[triangle.size()-1][i];
        }
        for(int i=triangle.size()-2;i>=0;i--)
        {
            vector<int>flat = dp;
            for(int j = i;j>=0;j--)
            {
                dp[j] = triangle[i][j] + min(flat[j],flat[j+1]);
            }
        }
        return dp[0];
    }
};
int main()
{
    vector<vector<int>>triangle;
    // init this first
    Solution obj1;
    return obj1.minimumTotal(triangle);
}