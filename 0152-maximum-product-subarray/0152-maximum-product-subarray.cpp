class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n),dp2(n);
        dp1[0]=nums[0];
        dp2[0]=nums[0];
        for(int i=1;i<n;i++){
            dp1[i]=min({nums[i],nums[i]*dp2[i-1],nums[i]*dp1[i-1]});
            dp2[i]=max({nums[i],nums[i]*dp2[i-1],nums[i]*dp1[i-1]});
        }
        return *max_element(dp2.begin(),dp2.end());
    }
};