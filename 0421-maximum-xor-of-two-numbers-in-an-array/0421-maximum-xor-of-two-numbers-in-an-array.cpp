class Solution {
public:

    struct TrieNode {

        TrieNode* child[2];

        TrieNode() {

            child[0] = NULL;
            child[1] = NULL;
        }

        // ~TrieNode() {

        //     delete child[0];
        //     delete child[1];
        // }
    };

    TrieNode* root;

    Solution() {

        root = new TrieNode();
    }

    // ~Solution() {

    //     delete root;
    // }

    void insert(int num) {

        TrieNode* node = root;

        for(int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if(node->child[bit] == NULL)
                node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {

        TrieNode* node = root;

        int ans = 0;

        for(int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            int opp = 1 - bit;
            if(node->child[opp]) {
                ans|=(1<<i);
                node = node->child[opp];
            }
            else {
                node = node->child[bit];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int num : nums)
            insert(num);

        int ans = 0;

        for(int num : nums) {

            ans = max(ans, getMaxXor(num));
        }

        return ans;
    }
};