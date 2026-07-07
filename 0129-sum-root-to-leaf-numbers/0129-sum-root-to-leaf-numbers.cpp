/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int &fsum,int tsum){
        if(!root) return;
        tsum=tsum*10+root->val;
        if(!root->left && !root->right){
            fsum+=tsum;
            return;}
        solve(root->left,fsum,tsum);
        solve(root->right,fsum,tsum);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int fsum=0,tsum=0;
        solve(root,fsum,tsum);
        return fsum;
    }
};