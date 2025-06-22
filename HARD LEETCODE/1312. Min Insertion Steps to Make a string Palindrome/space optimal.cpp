class Solution {
public:
    int minInsertions(string s) 
    {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int idx =s.size()-1;
        int idx2 = s2.size()-1;
        vector<int>prev(s2.size()+1,0),curr(s2.size()+1,0);
        for(int i=1;i<=s2.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s[i-1]==s2[j-1])curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return s.size()-prev[s2.size()];
    }
};