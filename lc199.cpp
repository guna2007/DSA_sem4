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

class Solution {
public:

    vector<int> levelorder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;

        if(!root) return res;
        q.push(root);

        TreeNode* curr;

        while(!q.empty())
        {
            int n = q.size();

            for(int i = 0;i < n;i++)
            {
                curr = q.front(); q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            res.push_back(curr->val);
        }

        return res;

    }


    vector<int> rightSideView(TreeNode* root) {
        return levelorder(root);
    }
};
