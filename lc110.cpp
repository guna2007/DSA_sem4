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
    bool res = true;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        int r = height(root->right);

        if (abs(r - l) > 1)
            res = false;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        height(root);
        return res;
    }
};

// signal based recursive solution
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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        if (l == -1)
            return -1;
        int r = height(root->right);
        if (r == -1)
            return -1;

        if (abs(r - l) > 1)
            return -1;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {

        return height(root) != -1;
    }
};
