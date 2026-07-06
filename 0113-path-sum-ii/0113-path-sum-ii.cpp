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
    void get_all(vector<vector<int>> &res,vector<int> &temp,TreeNode* root,int sum){
        if(!root) return;
        temp.push_back(root->val);
        if(!(root->left) && !(root->right)){
            if(sum==root->val){
            //temp.push_back(root->val);
            res.push_back(temp);}
            temp.pop_back();
            return;
        }
        get_all(res,temp,root->left,sum-root->val);
        //temp.pop_back();
        get_all(res,temp,root->right,sum-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        if(!root) return res;
        get_all(res,temp,root,targetSum);
        return res;
    }
};