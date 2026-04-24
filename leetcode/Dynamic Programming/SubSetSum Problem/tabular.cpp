class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
     vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,0));
     for(int i=0;i<dp.size();i++)
     {
         dp[i][0]=true;
     }
     if(arr[0]<=sum)dp[0][arr[0]]=true;
     for(int i=1;i<dp.size();i++)
     {
         for(int j=0;j<dp[0].size();j++)
         {
             bool take=false;
             if(j>=arr[i]) 
             {
                 take = dp[i-1][j-arr[i]];
             }
             bool not_take = dp[i-1][j];
             dp[i][j]= take||not_take;
         }
     }
     return dp[dp.size()-1][sum];
     
    }
};