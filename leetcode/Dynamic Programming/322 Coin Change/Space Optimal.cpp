class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++)
        {
            if(i==0)prev[i]=0;
            else
            {
                if(!(i%coins[0])) prev[i] = i/coins[0];
                else prev[i] = 1e9;
            }
        }
        for(int i=1;i<coins.size();i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                int take = 1e9;
                if(coins[i]<=j) take = 1 + curr[j-coins[i]];
                int move = prev[j];
                curr[j]=min(take,move);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans<1e9)return ans;
        else return -1;
    }
};