class Solution {
  public:
    int Solve(vector<vector<int>>&arr,int day,int last,vector<vector<int>>&dp)
    {
        if(day==0)
        {
            int max_i=0;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    max_i=max(max_i,arr[0][i]);
                }
            }
            return max_i;
        }
        if(dp[day][last]!=-1) return dp[day][last];
        int ans=0;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                int ans_i = arr[day][i] + Solve(arr,day-1,i,dp);
                ans= max(ans,ans_i);
            }
        }
        return dp[day][last]=ans;
    }
    int maximumPoints(vector<vector<int>>& arr) 
    {
        vector<vector<int>>dp(arr.size(),vector<int>(4,-1));
        int day=arr.size()-1;
        return Solve(arr,day,3,dp);
    }
};

int main()
{
    vector<vector<int>>arr;
    // init arr first
    Solution obj1;
    return obj1.maximumPoints(arr);
}