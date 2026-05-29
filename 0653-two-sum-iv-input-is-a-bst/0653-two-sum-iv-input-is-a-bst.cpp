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

    TreeNode* find(TreeNode* root, int target) {

        if(!root)
            return NULL;

        if(root->val == target)
            return root;

        if(target < root->val)
            return find(root->left, target);

        return find(root->right, target);
    }

    bool dfs(TreeNode* root, TreeNode* original, int k) {

        if(!root)
            return false;

        TreeNode* node = find(original, k - root->val);

        if(node && node != root)
            return true;

        return dfs(root->left, original, k) ||
               dfs(root->right, original, k);
    }

    bool findTarget(TreeNode* root, int k) {

        return dfs(root, root, k);
    }
};