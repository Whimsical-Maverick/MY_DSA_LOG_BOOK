class Solution {
public:
    int Solve(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(amount<0) return 1e9;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        if(idx==0)
        {
            if(amount==0) return 0;
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        int take = 1e9;
        if(coins[idx]<=amount) take = 1 + Solve(coins,amount-coins[idx],idx,dp);
        int move = 0 + Solve(coins,amount,idx-1,dp);
        return dp[idx][amount]=min(take,move);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int count=0;
        int idx = coins.size()-1;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res=Solve(coins,amount,idx,dp);
        if (res!=1e9) return res;
        else return -1;
    }
};