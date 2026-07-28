class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int> &c,int t,vector<int> &temp,int idx){
        if(t==0){
            res.push_back(temp);
            return;}
        if(idx==c.size() || t<0) return;
        temp.push_back(c[idx]);
        solve(res,c,t-c[idx],temp,idx);
        temp.pop_back();
        solve(res,c,t,temp,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(res,candidates,target,temp,0);
        return res;
    }
};