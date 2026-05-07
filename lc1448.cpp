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
    int helper(int maxval, TreeNode *node)
    {
        if (!node)
            return 0;
        int ans = 0;
        if (node->val >= maxval)
        {
            ans = 1;
            maxval = node->val;
        }

        return ans + helper(maxval, node->left) + helper(maxval, node->right);
    }

    int goodNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        // return helper(-1e4,root);
        int count = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, INT_MIN});

        while (!q.empty())
        {
            auto [node, prev] = q.front();
            q.pop();
            if (node->val >= prev)
            {
                count++;
                prev = node->val;
            }

            if (node->left)
                q.push({node->left, prev});
            if (node->right)
                q.push({node->right, prev});
        }

        return count;
    }
};
