class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size()+1,-1);
        int limit = nums.size()-1;
        dp[nums.size()] = 0;
        for(int i=dp.size()-2;i>=0;i--)
        {
            int choose = nums[i];
            int not_choose = 0;
            if(i+2<dp.size()) choose+=dp[i+2];
            if(i+1<dp.size()) not_choose+=dp[i+1];
            dp[i] = max(choose,not_choose);
        }
        return dp[0];
    }
};
int main()
{
    vector<int>eg;
    // initialise eg first
    Solution obj1;
    return obj1.rob(eg);
}