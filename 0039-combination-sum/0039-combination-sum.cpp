class Solution {
public:
    void all_comb(int i,vector<int> &can,int target,vector<int>&temp,vector<vector<int>> &res){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(i>=can.size() || target<0) return;
        temp.push_back(can[i]);
        all_comb(i,can,target-can[i],temp,res);
        temp.pop_back();
        all_comb(i+1,can,target,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        all_comb(0,candidates,target,temp,res);
        return res;
    }
};