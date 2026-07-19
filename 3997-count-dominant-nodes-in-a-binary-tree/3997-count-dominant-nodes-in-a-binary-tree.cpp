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

    int ans= 0;
    int f(TreeNode* node){
        if(!node) return -1;
        int l =f(node->left);
        int r= f(node->right);
        int mx = max({node->val,l,r});
        if(mx==node->val) ans++;
        return mx;
    }
    int countDominantNodes(TreeNode* root) {
        f(root);
        return ans;
    }
};