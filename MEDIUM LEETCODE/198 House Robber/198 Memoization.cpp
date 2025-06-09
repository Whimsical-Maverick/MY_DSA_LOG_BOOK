class Solution{
public:
int Solve(vector<int>&nums,int index,vector<int>&dp)
{
    if(index >= nums.size())
    {
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    return dp[index] = max(nums[index] + Solve(nums,index+2,dp),Solve(nums,index+1,dp));
}
int rob(vector<int>&nums)
{
    vector<int>dp(nums.size(),-1);
    int index=0;
    return Solve(nums,index,dp);
}
};
int main()
{
    vector<int>eg;
    // initialise eg first
    Solution obj1;
    return obj1.rob(eg);
}