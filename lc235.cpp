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
    TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        if (root == p || root == q)
            return root;
        TreeNode *left = helper(root->left, p, q);
        TreeNode *right = helper(root->right, p, q);

        if (left && right)
            return root;
        if (left)
            return left;
        if (right)
            return right;
        return NULL;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        return helper(root, p, q);
    }
};

// for BST

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
    TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root)
            return NULL;

        if (root->val < p->val && root->val < q->val)
            return helper(root->right, p, q);
        if (root->val > p->val && root->val > q->val)
            return helper(root->left, p, q);
        return root;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        return helper(root, p, q);
    }
};
