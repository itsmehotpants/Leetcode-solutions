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
    TreeNode* buildTree(vector<int>& po, vector<int>& io) {
        int rootIdx=0;
        return build(po,io,rootIdx,0,po.size()-1);
    }
    TreeNode* build(vector<int>& po, vector<int>& io,int &rootIdx,int l,int r){
        if(l>r) return NULL;
        int pivot = l;
        while(io[pivot]!=po[rootIdx]) pivot++;

        rootIdx++;
        TreeNode* node = new TreeNode(io[pivot]);
        node->left = build(po,io,rootIdx,l,pivot-1);
        node->right = build(po,io,rootIdx,pivot+1,r);
        return node;


    }
};