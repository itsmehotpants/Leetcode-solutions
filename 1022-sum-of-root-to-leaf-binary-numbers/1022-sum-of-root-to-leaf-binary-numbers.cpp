class Solution {
public:
    int helper(TreeNode* rt, int cur_val) {
        if(! rt) return 0;
        
        cur_val = (cur_val << 1) | rt->val;
        
        if(!rt->left && !rt->right)
			return cur_val;
			
        return helper(rt->left, cur_val) + helper(rt->right, cur_val);
    }
    
    int sumRootToLeaf(TreeNode* rt) {
        return helper(rt, 0);
    }
};