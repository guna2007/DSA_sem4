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
    int helper(TreeNode *root, int &ans)
    {
        // base
        if (!root)
            return 0;

        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        // path with curr as top
        ans = max(ans, root->val + max(0, l) + max(0, r));
        // gives the max it can give to its parent
        return root->val + max({l, r, 0});
    }

    int maxPathSum(TreeNode *root)
    {
        // do postorder dfs with using state as ans keeping max until what seen
        // for that use base case as if both empty that itself is val
        // and for each parent check if node + each child > node then its in path
        // like in kadanes algo
        // and store in state ans if its max
        // like that we can do in order n
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};
