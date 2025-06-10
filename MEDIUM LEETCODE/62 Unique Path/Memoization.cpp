#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int Solve(int row, int col, int m, int n, vector<vector<int>>& dp) 
    {
        if (row >= m || col >= n) return 0;
        if (row == m - 1 && col == n - 1) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = Solve(row + 1, col, m, n, dp) + Solve(row, col + 1, m, n, dp);
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return Solve(0, 0, m, n, dp);
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    Solution obj;
    cout << obj.uniquePaths(m, n) << endl;

    return 0;
}
