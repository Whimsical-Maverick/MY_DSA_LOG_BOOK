class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int two_ahead = 0;
        int one_ahead = 0;
        for (int i = n - 1; i >= 0; i--) {
            int pick = nums[i] + two_ahead;
            int skip = one_ahead;
            int curr = max(pick, skip);
            two_ahead = one_ahead;
            one_ahead = curr;
        }
        return one_ahead;
    }
};
int main()
{
    vector<int>eg;
    // initialise eg first
    Solution obj1;
    return obj1.rob(eg);
}
