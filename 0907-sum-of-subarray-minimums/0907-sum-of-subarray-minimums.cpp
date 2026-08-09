class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod=1e9+7;
        int n=arr.size();
        vector<int> ps(n,-1),ns(n,n);
        stack<int> stk,st;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            ns[i]=stk.empty()?n:stk.top();
            stk.push(i);
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            ps[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        long long tot=0LL;
        for(int i=0;i<n;i++){
            int l=i-ps[i];
            int r=ns[i]-i;
            long long cont=1LL*arr[i]*l*r;
            tot=(tot+cont)%mod;
        }
        return tot;
    }
};