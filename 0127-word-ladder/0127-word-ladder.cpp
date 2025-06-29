class Solution {
public:
    int Solve(vector<string>&wordList,unordered_map<string,int>&mp,set<string>&s,string&beginWord,string&endWord,int count)
    {
        queue<string>q;
        q.push(beginWord);
        mp[beginWord]=1;
        while(!q.empty())
        {
            int level =q.size();
            for(int i=0;i<level;i++)
            {
                string myword = q.front();
                mp[myword]=1;
                q.pop();
                for(int i=0;i<myword.size();i++)
                {
                for(int j=0;j<26;j++)
                {
                    string word = myword;
                    word[i] = 97+j;
                    if(word==endWord && s.find(endWord)!=s.end())return count+1;
                    if(s.find(word)!=s.end() && mp.find(word)==mp.end())
                    {
                        q.push(word);
                        mp[word]=1;
                    }
                }
                }
            }
            count++;
            
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_map<string,int>mp;
        set<string>s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end())return 0;
        int count=1;
        return Solve(wordList,mp,s,beginWord,endWord,count);
    }
};