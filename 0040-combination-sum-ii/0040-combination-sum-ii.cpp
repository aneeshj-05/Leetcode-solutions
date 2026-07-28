class Solution {
public:
    void all_sum(int i,vector<int> &candidates,int target,vector<int> &temp,vector<vector<int>> &res){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(i>=candidates.size()||target<0) return;
        temp.push_back(candidates[i]);
        all_sum(i+1,candidates,target-candidates[i],temp,res);
        temp.pop_back();
        int h=i+1;
        while(h<candidates.size() && candidates[h]==candidates[h-1]) h++;
        all_sum(h,candidates,target,temp,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        all_sum(0,candidates,target,temp,res);
        return res;
    }
};