class Solution {
public:
    void solve(vector<string> &ans,string temp,int c,int o,int n){
        if(o>n || c>n) return;
        if(c>o) return;
        if((c+o)==2*n){
            ans.push_back(temp);
            return;
        }
        temp.push_back('(');
        solve(ans,temp,c,o+1,n);
        temp.pop_back();
        temp.push_back(')');
        solve(ans,temp,c+1,o,n);
        temp.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        solve(ans,temp,0,0,n);
        return ans;
    }
};