class Solution {
public:
    bool ispalindrome(string st,int s,int e){
            while(s<=e) if(st[s++]!=st[e--]) return false;
            return true;
    }
    void solve(string s,int idx,vector<vector<string>> &res,vector<string> &temp){
        if(idx==s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,res,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(s,0,res,temp);
        return res;
    }
};