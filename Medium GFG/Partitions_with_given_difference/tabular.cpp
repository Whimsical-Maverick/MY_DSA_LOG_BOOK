class Solution {
  public:
    int Solve(vector<int>&arr,int&total,int sum,int idx,int&d,vector<vector<int>>&dp)
    {
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        if(idx==0)
        {
            int new_sum=sum+arr[0];
            int count=0;
            if(new_sum>=(total-new_sum) && 2*(new_sum)-total==d)count++;
            if(sum>=(total-sum) && 2*(sum)-total == d)count++;
            return dp[idx][sum]=count;
        }
        return dp[idx][sum]=Solve(arr,total,sum+arr[idx],idx-1,d,dp) + Solve(arr,total,sum,idx-1,d,dp);
    }
    int countPartitions(vector<int>& arr, int d)
    {
        int sum=0;
        int total=0;
        for(auto element : arr)
        {
            total+=element;
        }
        int idx = arr.size()-1;
        vector<vector<int>>dp(arr.size(),vector<int>(total+1,-1));
        return Solve(arr,total,sum,idx,d,dp);
    }
};