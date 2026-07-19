class Solution {
public:
    void bfs(int r,int c,vector<vector<bool>> &vis,vector<vector<char>> &grid){
        int m=grid.size(),n=grid[0].size();
        vis[r][c]=true;
        queue<pair<int,int>> q;
        q.push({r,c});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                    int fr=row+dr[i];
                    int fc=col+dc[i];
                    if(fr>=0 && fr<m && fc>=0 && fc<n && !vis[fr][fc] && grid[fr][fc]=='1'){
                        vis[fr][fc]=true;
                        q.push({fr,fc});
                    }
            }
                
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};