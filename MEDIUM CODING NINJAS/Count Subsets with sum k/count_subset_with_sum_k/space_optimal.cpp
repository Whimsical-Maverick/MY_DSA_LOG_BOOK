int findWays(vector<int>& arr, int k)
{
	vector<int>prev(k+1,0);
	prev[0]=1;
    if(arr[0]<=k)prev[arr[0]]++;
	for(int i=1;i<arr.size();i++)
	{
		vector<int>curr(k+1,0);
		curr[0]=1;
		for(int j=0;j<k+1;j++)
		{
			curr[j] = prev[j];
			if(j-arr[i]>=0)
			{
               curr[j]+=prev[j-arr[i]];
			   curr[j]=curr[j]%(1000000007);
			}
		}
		prev = curr;
	}
	return prev[k];
}