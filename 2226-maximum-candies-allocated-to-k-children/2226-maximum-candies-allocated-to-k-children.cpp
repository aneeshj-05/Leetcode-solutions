class Solution {
public:
    long long cnt(vector<int>& arr,int m){
        long long a=0;
        for(auto c:arr){
            a+=(c/m);
        }
        return a;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,r=*max_element(candies.begin(),candies.end());
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        if(sum<k) return 0;
        while(l<r){
            int mid=l+(r-l+1)/2;
            long long abc=cnt(candies,mid);
            if(abc>=k) l=mid;
            else r=mid-1;
        }
        return l;
    }
};