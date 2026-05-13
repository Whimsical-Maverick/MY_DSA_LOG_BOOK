class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size();
        int num_squares = n*n;
        vector<int>vis(n*n + 1,0);
        queue<pair<int,int>>q;
        q.push({0,1});
        vis[1]=1;
        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            int moves = el.first;
            int num = el.second;
            if(num==n*n)return moves;
            for(int dice=1;dice<=6;dice++)
            {
                int new_num = num + dice;
                
                if(new_num>n*n)break;

                int r = (new_num-1)/n;
                int c = (new_num-1)%n;

                int nr = n-1-r;
                if(r%2==1)
                {
                    c = n-1-c;
                }

                if(board[nr][c]!=-1)new_num = board[nr][c];

                if(vis[new_num]==0)
                {
                    vis[new_num]=1;
                    q.push({moves+1,new_num});
                }

            }
        }
        return -1;
    }
};