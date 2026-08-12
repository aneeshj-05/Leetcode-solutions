class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev(n,-1),next(n,n);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            prev[i]=stk.empty()?-1:stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            next[i]=stk.empty()?n:stk.top();
            stk.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int wid=next[i]-prev[i]-1;
            int a=heights[i]*wid;
            ans=max(ans,a);
        }
        return ans;
    }
};