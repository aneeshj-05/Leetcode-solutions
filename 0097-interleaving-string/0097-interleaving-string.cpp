class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(),n=s2.size();
        if(m+n!=s3.size()) return false;
        if(s1==s3 || s2==s3) return true;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) if(dp[0][i-1]==true && s2[i-1]==s3[i-1]) dp[0][i]=true;
        for(int i=1;i<=m;i++) if(dp[i-1][0]==true && s1[i-1]==s3[i-1]) dp[i][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if((dp[i][j-1]==true && s2[j-1]==s3[i+j-1]) || (dp[i-1][j]==true && s1[i-1]==s3[i+j-1])) dp[i][j]=true;
            }
        }
        return dp[m][n];
    }
};