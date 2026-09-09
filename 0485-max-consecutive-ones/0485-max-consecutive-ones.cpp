class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int gc=0,oc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) oc++;
            else{
                gc=max(gc,oc);
                oc=0;
            }
        }
        gc=max(oc,gc);
        return gc;
    }
};