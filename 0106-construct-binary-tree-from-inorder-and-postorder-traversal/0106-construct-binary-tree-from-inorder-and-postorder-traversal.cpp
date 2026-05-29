class Solution {
public:

    TreeNode* build(vector<int>& post,
                    vector<int>& in,
                    int& rootIdx,
                    int l,
                    int r) {

        if(l > r)
            return NULL;

        int pivot = l;

        while(in[pivot] != post[rootIdx])
            pivot++;

        TreeNode* node =
            new TreeNode(in[pivot]);

        rootIdx--;

        node->right =
            build(post, in, rootIdx,
                  pivot + 1, r);

        node->left =
            build(post, in, rootIdx,
                  l, pivot - 1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int rootIdx = postorder.size() - 1;

        return build(postorder,
                     inorder,
                     rootIdx,
                     0,
                     inorder.size() - 1);
    }
};