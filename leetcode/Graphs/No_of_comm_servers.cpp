class Solution {
private:
    int BFS(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int count)
    {
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            auto element = q.front();
            q.pop();
            int row = element.first;
            int col = element.second;
            for(int c=0;c<grid[0].size();c++)
            {
                if(c!=col && grid[row][c]==1 && vis[row][c]==0)
                {
                    count++;
                    vis[row][c]=1;
                    q.push({row,c});
                }
            }
            for(int r=0;r<grid.size();r++)
            {
                if(r!=row && grid[r][col]==1 && vis[r][col]==0)
                {
                    count++;
                    vis[r][col]=1;
                    q.push({r,col});
                }
            }
        }
        if(count>0)return count+1;
        return count;
    }
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int count=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
               if(grid[i][j]==1 && vis[i][j]==0)
               {
                  int local_count=0;
                  vis[i][j]=1;
                  count+=BFS(i,j,vis,grid,local_count);
               }
            }
        }
        return count;
    }
};