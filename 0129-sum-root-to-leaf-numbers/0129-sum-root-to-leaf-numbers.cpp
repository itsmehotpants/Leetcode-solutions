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
int ans=0;
    void help(TreeNode*root,int sum){
        if(!root) return;
        sum = sum*10+root->val;
        if(!root->left && !root->right) ans+=sum;;
        help(root->left,sum);
        help(root->right,sum);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        help(root,sum);
        return ans;
    }
};