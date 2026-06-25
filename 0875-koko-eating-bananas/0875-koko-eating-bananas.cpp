class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int hrs=0,l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=(l+r)/2;
            hrs=0;
            for(int i=0;i<piles.size();i++){
                hrs+=(piles[i]+mid-1)/mid;
            }
            if(hrs>h) l=mid+1;
            else r=mid;
        }
        return l;
    }
};