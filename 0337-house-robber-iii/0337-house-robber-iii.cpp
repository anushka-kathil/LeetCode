class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* node) {
        if (!node) return 0;
        if (dp.count(node)) return dp[node];

        int pick = node->val;
        if (node->left)  pick += rob(node->left->left) + rob(node->left->right);
        if (node->right) pick += rob(node->right->left) + rob(node->right->right);

        int skip = rob(node->left) + rob(node->right);

        return dp[node] = max(pick, skip);
    }
};