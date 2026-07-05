class Solution {
public:
    bool solve(vector<vector<char>> &board,string word,int r,int c,int m,int n,int idx){
        if(idx==word.size()) return true;
        if(r==-1 || c==-1 || r==m || c==n) return false;
        if(board[r][c]=='#') return false;
        if(board[r][c]!=word[idx]) return false;
        char orig=board[r][c];
        board[r][c]='#';
        bool found=(solve(board,word,r+1,c,m,n,idx+1) || solve(board,word,r-1,c,m,n,idx+1) ||solve(board,word,r,c+1,m,n,idx+1) || solve(board,word,r,c-1,m,n,idx+1));
        board[r][c]=orig;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,word,i,j,m,n,0)) return true;
            }
        }
        return false;
    }
};