class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        for(int i=0;i<nums.size();i++){
            int inv=target-nums[i];
            if(index.find(inv)!=index.end()) return {index[inv],i};
            index[nums[i]]=i;
        }
        return {};
    }
};