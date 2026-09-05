class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for(auto v:intervals){
            if(!res.empty() && res.back()[1]>=v[0]){
                res.back()[0]=min(res.back()[0],v[0]);
                res.back()[1]=max(res.back()[1],v[1]);
            } 
            else res.push_back(v);
        }
        return res;
    }
};