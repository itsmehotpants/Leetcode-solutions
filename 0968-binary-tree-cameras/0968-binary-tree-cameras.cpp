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
//0->uncovered,
//1 cam on me
// 2 covered by cam
int cam;

int dfs(TreeNode* node){
    if(!node) return 2;
    int l = dfs(node->left),r= dfs(node->right);
    if(l==0 || r==0){
        cam++;
        return 1;
    }
    else if(l==1 || r==1) return 2;
    return 0;
}

    int minCameraCover(TreeNode* root) {
        cam = 0;
        if(dfs(root)==0) cam++;
        return cam;
    }
};