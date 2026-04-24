class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        for(int i=0;i<=amount;i++)
        {
            if(i==0)dp[0][i]=0;
            else
            {
                if(!(i%coins[0])) dp[0][i] = i/coins[0];
                else dp[0][i] = 1e9;
            }
        }
        for(int i=1;i<coins.size();i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                int take = 1e9;
                if(coins[i]<=j) take = 1 + dp[i][j-coins[i]];
                int move = dp[i-1][j];
                dp[i][j]=min(take,move);
            }
        }
        int ans = dp[coins.size()-1][amount];
        if(ans<1e9)return ans;
        else return -1;
    }
};