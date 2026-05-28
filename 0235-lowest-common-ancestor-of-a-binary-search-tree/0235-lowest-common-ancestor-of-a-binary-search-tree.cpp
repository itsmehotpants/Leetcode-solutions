/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// //recursive
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root ==NULL) return NULL;
//         int x  =root->val;
//         int maxm = max(p->val,q->val);
//         int minm = min(p->val,q->val);
//         if(x>maxm) return lowestCommonAncestor(root->left,p,q);
//         if(x<minm) return lowestCommonAncestor(root->right,p,q);
//         else return root;
//     }
// };
//iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){

            if(p->val < root->val && q->val < root->val)
                root = root->left;

            else if(p->val > root->val && q->val > root->val)
                root = root->right;

            else
                return root;
        }

        return NULL;
    }
};