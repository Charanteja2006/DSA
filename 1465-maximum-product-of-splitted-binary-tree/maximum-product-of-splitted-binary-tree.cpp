class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long ans = 0;

    long long traversal(TreeNode* root) {
        if (!root) return 0;
        root->val += traversal(root->left) + traversal(root->right);
        return root->val;
    }

    void maxSum(TreeNode* root, long long tot) {
        if (!root) return;

        long long part = root->val;
        long long prod = part * (tot - part);
        ans = max(ans, prod);

        maxSum(root->left, tot);
        maxSum(root->right, tot);
    }

    int maxProduct(TreeNode* root) {
        long long tot = traversal(root);
        maxSum(root, tot);
        return ans % MOD;
    }
};
