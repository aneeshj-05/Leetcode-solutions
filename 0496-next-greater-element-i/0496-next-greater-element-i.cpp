class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(),0);
        stack<int> stk;
        int n=nums2.size();
        stk.push(0);
        for(int i=1;i<n;i++){
            while(!stk.empty() && nums2[i]>nums2[stk.top()]){
                int s=stk.top();
                stk.pop();
                nge[s]=nums2[i];
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int s=stk.top();
            stk.pop();
            nge[s]=-1;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)  mp[nums2[i]]=nge[i];
        vector<int> res;
        for(auto n:nums1) res.push_back(mp[n]);
        return res;
    }
};