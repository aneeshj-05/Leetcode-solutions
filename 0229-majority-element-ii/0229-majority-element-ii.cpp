class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,ele1=INT_MIN,ele2=INT_MIN;
        for(auto n:nums){
            if(cnt1==0 && n!=ele2){
                cnt1=1;
                ele1=n;
            }
            else if(cnt2==0 && n!=ele1){
                cnt2=1;
                ele2=n;
            }
            else if(n==ele1) cnt1++;
            else if(n==ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=cnt2=0;
        vector<int> res;
        for(auto n:nums){
            if(n==ele1) cnt1++;
            else if(n==ele2) cnt2++;
        }
        int n=nums.size();
        if(cnt1>n/3) res.push_back(ele1);
        if(cnt2>n/3) res.push_back(ele2);
        return res;
    }
};