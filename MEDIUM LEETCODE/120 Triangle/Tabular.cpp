class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
       vector<vector<int>>dp;
       for (int i = 0; i < triangle.size(); ++i) 
       {
         dp.push_back(vector<int>(triangle[i].size(), -1));
       }
       for(int i=0;i<dp[dp.size()-1].size();i++)
       {
         dp[dp.size()-1][i] = triangle[triangle.size()-1][i];
       }
       for(int i=dp.size()-2;i>=0;i--)
       {
          for(int j = dp[i].size()-1;j>=0;j--)
          {
            dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
          }
       }
       return dp[0][0];
    }
};
int main()
{
    vector<vector<int>>triangle;
    // init this first
    Solution obj1;
    return obj1.minimumTotal(triangle);
}