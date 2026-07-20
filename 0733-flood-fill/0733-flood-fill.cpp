class Solution {
public:
    void dfs(vector<vector<int>> &img,int r,int c,int color,int ini,vector<vector<bool>> &visit){
        img[r][c]=color;
        visit[r][c]=true;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        int m=img.size();
        int n=img[0].size();
        for(int i=0;i<4;i++){
            int cr=r+dr[i];
            int cc=c+dc[i];
            if(cr>=0 && cr<m && cc>=0 && cc<n && !visit[cr][cc] && img[cr][cc]==ini) dfs(img,cr,cc,color,ini,visit);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        int m=image.size(),n=image[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        dfs(image,sr,sc,color,ini,visit);
        return image;
    }
};