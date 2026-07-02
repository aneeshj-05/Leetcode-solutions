class Solution {
public:
    void all_comb(int i,int k,int n,vector<int> &temp,vector<vector<int>> &res){
        if(temp.size()==k){
            if(n==0){
                res.push_back(temp);
                return;
            }
            else return;
        }
        if(i>9) return;
        if(n<0) return;
        temp.push_back(i);
        all_comb(i+1,k,n-i,temp,res);
        temp.pop_back();
        all_comb(i+1,k,n,temp,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        all_comb(1,k,n,temp,res);
        return res;
    }
};