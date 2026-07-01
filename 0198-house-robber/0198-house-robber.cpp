class Solution {
public:
    int rob(vector<int>& nums) {
        int p2=0,p1=0;
        for(auto m:nums){
            int curr=max(p1,p2+m);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};