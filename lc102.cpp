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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        vector<int> level;
        int prev_lev = 0;
        while (!q.empty())
        {
            auto [node, lev] = q.front();
            q.pop();
            if (!node)
                continue;

            if (prev_lev != lev)
            {
                res.push_back(level);
                prev_lev = lev;
                level.clear();
            }

            level.push_back(node->val);

            if (node->left)
                q.push({node->left, lev + 1});
            if (node->right)
                q.push({node->right, lev + 1});
        }

        if (level.size() != 0)
            res.push_back(level);

        return res;
    }
};

// approach2 queue size

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> level;

            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                auto node = q.front();
                q.pop();

                if (!node)
                    continue;
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (level.size())
                res.push_back(level);
        }
        return res;
    }
};
