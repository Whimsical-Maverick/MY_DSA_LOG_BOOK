int Solve(vector<int>&arr,int idx,int k,unordered_map<string,int>&mp)
{
	string key = to_string(idx)+'#'+to_string(k);
	if(mp.find(key)!=mp.end())return mp[key];
	if(k<0 || idx<0)return 0;
	if(idx==0)
	{
		int count=0;
        if(k==0) count++;
		if(k==arr[idx]) count++;
		return count;
	}
	return mp[key]=(Solve(arr,idx-1,k-arr[idx],mp)+Solve(arr,idx-1,k,mp))%1000000007;
}
int findWays(vector<int>& arr, int k)
{
	unordered_map<string,int>mp;
	int idx = arr.size()-1;
	return ((Solve(arr,idx,k,mp))%(1000000007));
}
