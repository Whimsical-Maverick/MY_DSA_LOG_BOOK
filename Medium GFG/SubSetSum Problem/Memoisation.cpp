class Solution {
  public:
    void Solve(bool&flag,int idx,int t_sum,vector<int>&arr,int&sum,vector<vector<int>>& memo)
    {
      if(t_sum==sum)
      {
          flag=1;
          return;
      }
      if(t_sum>sum || idx<0 || flag)
      {
          return ;
      }
       if(memo[idx][t_sum]!=-1)
       {
           if(memo[idx][t_sum]==1) flag=1;
           return;
       }
       int sum1=t_sum;
       int sum2=t_sum;
       sum1+=arr[idx];
       Solve(flag,idx-1,sum1,arr,sum,memo);
       Solve(flag,idx-1,sum2,arr,sum,memo);
       if(flag==1) memo[idx][t_sum]=1;
       else memo[idx][t_sum]=0;
       return;
    }
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
     vector<vector<int>>memo(arr.size(),vector<int>(sum+1,-1));
     int  t_sum=0;
     bool flag =0;
     int idx=arr.size()-1;
     Solve(flag, idx, t_sum, arr, sum,memo);
     if(flag)
     {
         return true;
     }
     else
     {
         return false;
     }
    }
};