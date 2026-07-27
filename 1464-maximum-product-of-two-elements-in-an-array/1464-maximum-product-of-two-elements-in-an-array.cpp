class Solution {
public:
    int maxProduct(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        int fl=-1,sl=-1;
        for(auto n:nums){
            if(n>fl){
                sl=fl;
                fl=n;
            }
            else if(n>sl) sl=n;
        }
        return (fl-1)*(sl-1);
    }
};