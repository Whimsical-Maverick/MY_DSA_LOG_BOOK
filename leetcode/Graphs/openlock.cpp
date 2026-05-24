class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        for(auto el : deadends)
        {
            if(el=="0000")return -1;
        }
        unordered_set<string>st(deadends.begin(),deadends.end());
        queue<pair<int,string>>q;
        q.push({0,"0000"});
        st.insert("0000");
        while(!q.empty())
        {
            auto el = q.front();
            string node = el.second;
            int steps = el.first;
            q.pop();
            if(node==target)return steps;
            for(int i=0;i<node.size();i++)
            {
                string temp = node;
                temp[i] = temp[i]=='9'?'0':temp[i] + 1;
                if(st.find(temp)==st.end())
                {
                    st.insert(temp);
                    q.push({steps+1,temp});
                }

                temp = node;
                temp[i] = temp[i]=='0'?'9':temp[i] - 1;
                if(st.find(temp)==st.end())
                {
                    st.insert(temp);
                    q.push({steps+1,temp});
                }
            }
        }
        return -1;
    }
};