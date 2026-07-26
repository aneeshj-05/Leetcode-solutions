class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),cnt=0;
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(l==1) dp[i][j]=true;
                else if(l==2) dp[i][j]=s[i]==s[i+1];
                else dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                if(dp[i][j]) cnt++;
            }
        }
        return cnt;
    }
};