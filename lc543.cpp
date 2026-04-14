// brute
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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r);
    }
    int res = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return res = max(l + r, res);
    }
};

// optimal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        res = max(l + r, res);
        return 1 + max(l, r);
    }
    int res = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);

        return res;
    }
};
