class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto it1=min_element(nums.begin(),nums.end());
        auto it2=max_element(nums.begin(),nums.end());
        int i1=it1-nums.begin();
        int i2=it2-nums.begin();
        int n=nums.size();
        if(i1>i2) swap(i1,i2);
        int l=i2+1,r=n-i1,b=(i1+1)+(n-i2);
        return min({l,r,b});
    }
};