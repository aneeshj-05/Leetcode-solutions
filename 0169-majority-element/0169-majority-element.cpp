class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,ele=INT_MIN;
        for(auto n:nums){
            if(cnt==0){
                ele=n;
                cnt=1;
            }
            else if(ele==n) cnt++;
            else cnt--;
        }
        return ele;
    }
};