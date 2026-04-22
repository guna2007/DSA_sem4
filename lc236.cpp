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
        // my eff logic is
        // postorder func with 2 vals isp,isq and lca if both 1
        // do postorder initially those -1,-1
        // if found 1,1-> if both are 1,1 means found
        // then return that node all way up!
        return helper(root, p, q);
    }
};
