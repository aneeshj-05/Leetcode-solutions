class Solution {
public:
    void add_elements(int idx,vector<vector<int>> &res,vector<int> &temp,vector<int> &nums,set<vector<int>> &s){
        if(idx>=nums.size()){
            if(!s.count(temp)){
            s.insert(temp);
            res.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[idx]);
        add_elements(idx+1,res,temp,nums,s);
        temp.pop_back();
        add_elements(idx+1,res,temp,nums,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        add_elements(0,res,temp,nums,s);
        return res;
    }
};