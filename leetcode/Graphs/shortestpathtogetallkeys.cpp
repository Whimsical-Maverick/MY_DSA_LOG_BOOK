class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int num_keys=0;
        queue<vector<int>>q;
        vector<pair<int,int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int startrow = 0;
        int startcol = 0;
        int maxkey=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='@' || grid[i][j]=='.' || grid[i][j]=='#' || (grid[i][j] >= 'A' && grid[i][j] <='Z'))
                {
                    if(grid[i][j]=='@')
                    {
                       startrow = i;
                       startcol = j;
                    }
                    continue;
                }
                num_keys++;
            }
        }

        vector<vector<vector<int>>>vis(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(64,0)));//as u need 1<<num_keys -1 indexes;

        q.push({0,startrow,startcol,0});
        vis[startrow][startcol][0]=1;
        int targetMask=(1<<num_keys)-1;//see note for exp

        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            int steps = el[0];
            int row = el[1];
            int col = el[2];
            int mask = el[3];
            if(mask==targetMask)return steps;
            for(auto dir : dirs)
            {
                int nr = row + dir.first;
                int nc = col + dir.second;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size())
                {
                    int new_mask=mask;
                    if(grid[nr][nc]!='#')
                    {
                        if(grid[nr][nc]>='a' && grid[nr][nc]<='z')
                        {
                            int collected_key = 1<<(grid[nr][nc]-'a');
                            new_mask = new_mask|collected_key;
                        }
                        if(grid[nr][nc]>='A' && grid[nr][nc]<='Z')
                        {
                            int required_mask = 1<<(grid[nr][nc]-'A');
                            if((new_mask & required_mask)==0)continue;
                        }
                        if(!vis[nr][nc][new_mask])
                        {
                            vis[nr][nc][new_mask]=1;
                            q.push({steps+1,nr,nc,new_mask});
                        }
                    }
                }
            }

        }

        return -1;
    }
};