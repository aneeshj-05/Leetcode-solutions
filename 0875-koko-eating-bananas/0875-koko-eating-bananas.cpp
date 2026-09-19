class Solution {
public:
bool check(long long m,long long h,vector<int> &piles){
            long long hrs=0;
            for(auto p:piles) hrs+=(p+m-1)/m;
            return hrs<=h;
        }
    long long minEatingSpeed(vector<int>& piles, long long h) {
        long long l=1,r=*max_element(piles.begin(),piles.end());
        long long ans=-1;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(mid,h,piles)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};