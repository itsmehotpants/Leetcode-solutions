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
int maxm=INT_MIN;

int help(TreeNode*node){
            if(!node) return 0;

int lsum= max(0,help(node->left));
int rsum= max(0,help(node->right));
 maxm= max(maxm,lsum+rsum+node->val);
return node->val+max(lsum,rsum);
}
    int maxPathSum(TreeNode* root) {
        help(root);
        return maxm;


    }
};