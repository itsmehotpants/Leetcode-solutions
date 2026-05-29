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

void solve(TreeNode*root,int sum, vector<vector<int>>&res,vector<int>&v){
    if(!root) return;
    sum-=root->val;
    v.push_back(root->val);
    if(sum==0&&!root->left&&!root->right) res.push_back(v);
    solve(root->left,sum,res,v);
    solve(root->right,sum,res,v);
    v.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>v;
        solve(root,sum,res,v);
        return res;
    }
};