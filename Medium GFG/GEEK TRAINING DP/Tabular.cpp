class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) 
    {
        vector<vector<int>>dp(arr.size(),vector<int>(4,-1));
        dp[0][0] = max(arr[0][1],arr[0][2]);
        dp[0][1] = max(arr[0][0],arr[0][2]);
        dp[0][2] = max(arr[0][0],arr[0][1]);
        dp[0][3] = max(arr[0][0],max(arr[0][1],arr[0][2]));
        for(int day=1;day<dp.size();day++)
        {
           for(int last=0;last<4;last++)
           {
               for(int task =0;task<3;task++)
               {
                   if(last!=task)
                   {
                     dp[day][last] = max(dp[day][last],arr[day][task] + dp[day-1][task]);
                   }
               }
           }
        }
        return dp[arr.size()-1][3];
    }
};
int main()
{
    vector<vector<int>>arr;
    //init arr first;
    Solution obj1;
    return obj1.maximumPoints(arr);
}