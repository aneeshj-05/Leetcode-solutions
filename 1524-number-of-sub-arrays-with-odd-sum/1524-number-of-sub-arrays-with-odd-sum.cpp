class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        int n=arr.size();
        int even=1,odd=0;
        int prefix=0,res=0;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
            if(prefix%2==0){
                res+=odd;
                even++;
            }
            else{
                res+=even;
                odd++;
            }
            res%=MOD;
        }
        return res;
    }
};