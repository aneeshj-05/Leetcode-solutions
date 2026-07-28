class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1) return s;
        string res="";
        vector<int> f(26,0);
        for(auto c:s){
            f[c-'a']++;
        }
        int oi=-1;
        string temp="";
        for(int i=0;i<26;i++){
            if(f[i]%2==1) oi=i;
            f[i]=f[i]/2;
        }
        for(int i=0;i<26;i++){
            while(f[i]--){
                temp+=char(i+'a');
            }
    }
        if(oi!=-1) res=temp+char(oi+'a');
        else res=temp;
        reverse(temp.begin(),temp.end());
        res+=temp;
        return res;
    }
};