class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int l=0,ma=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                l++;
            }
            ma=max(ma,r-l+1);
        }
        return ma;
    }
};