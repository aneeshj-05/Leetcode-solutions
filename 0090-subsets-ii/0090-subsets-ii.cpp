class Solution {
public:
    void add_elements(int idx,vector<vector<int>> &res,vector<int> &temp,vector<int> &nums){
        if(idx>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        add_elements(idx+1,res,temp,nums);
        temp.pop_back();
        int h=idx+1;
        while(h<nums.size() && nums[h]==nums[h-1]) h++;
        add_elements(h,res,temp,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        add_elements(0,res,temp,nums);
        return res;
    }
};