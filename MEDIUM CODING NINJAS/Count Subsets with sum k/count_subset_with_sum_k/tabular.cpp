int findWays(vector<int>& arr, int k)
{
	vector<vector<int>>dp(arr.size(),vector<int>(k+1,0));
	dp[0][0]=1;
	if(arr[0]<=k)dp[0][arr[0]]++;
	for(int i=1;i<arr.size();i++)
	{
		for(int j=0;j<k+1;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j-arr[i]>=0)
			{
               dp[i][j]+=dp[i-1][j-arr[i]];
			   dp[i][j]=dp[i][j]%(1000000007);
			}
		}
	}
	return dp[arr.size()-1][k];
}
