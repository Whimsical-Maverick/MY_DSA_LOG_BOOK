class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int idx1=text1.size()-1;
        int idx2=text2.size()-1;
        vector<int>curr(text2.size()+1,0),prev(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1]) curr[j] = 1+prev[j-1];
                else curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        } 
        return prev[text2.size()];
    }
};