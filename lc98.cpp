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
using ll = long long;
class Solution
{
public:
    bool inorder(TreeNode *root, ll &prev)
    {
        if (!root)
            return true;
        int left = inorder(root->left, prev);
        if (root->val <= prev)
            return false;
        prev = root->val;
        int right = inorder(root->right, prev);
        return left && right;
    }

    bool isValidBST(TreeNode *root)
    {
        ll prev = LLONG_MIN;
        return inorder(root, prev);
    }
};

///////////////

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
using ll = long long;
class Solution
{
public:
    bool helper(TreeNode *node, ll left, ll right)
    {
        if (!node)
            return true;
        if (!(node->val > left && node->val < right))
            return false;
        return helper(node->left, left, node->val) && helper(node->right, node->val, right);
    }

    bool isValidBST(TreeNode *root)
    {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
