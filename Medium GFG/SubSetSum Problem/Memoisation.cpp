class Solution {
  public:
    bool Solve(int idx,vector<int>&arr,int target,vector<vector<int>>&dp)
    {
       if(target==0) return true;
       if(idx==0)
       {
           return (target==arr[0]);
       }
       if(dp[idx][target]!=-1)return dp[idx][target];
       bool take=false;
       if(target>=arr[idx]) 
       {
           take = Solve(idx-1,arr,target-arr[idx],dp);
       }
       bool not_take = Solve(idx-1,arr,target,dp);
       return dp[idx][target]=(take||not_take);
    }
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
     vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
     int idx=arr.size()-1;
     return Solve(idx,arr, sum,dp);
    }
};