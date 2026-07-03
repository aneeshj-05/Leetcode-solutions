class Solution {
public:
    void permu(int i,vector<vector<int>> &res,vector<int> &nums){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            permu(i+1,res,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permu(0,res,nums);
        return res;
    }
};