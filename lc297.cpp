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

class Codec
{
public:
    void helper1(TreeNode *root, string &s)
    {
        if (!root)
        {
            s += "N,";
            return;
        }
        s += to_string(root->val);
        s += ",";
        helper1(root->left, s);
        helper1(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        helper1(root, s);
        cout << s;
        return s;
    }

    TreeNode *helper2(int &idx, int n, string &s)
    {
        // extract s[idx] until delimiter , is seen
        string temp = "";

        while (idx < n && s[idx] != ',')
        {
            temp += s[idx];
            idx++;
        }

        // check is it num or N
        if (temp == "N")
        {
            idx++;
            return NULL;
        }

        // if its not null convert that into a number
        int num = stoi(temp);

        // create new node with that val
        TreeNode *root = new TreeNode(num);

        // then call left,right
        idx++;
        root->left = helper2(idx, n, s);
        root->right = helper2(idx, n, s);

        // return that root
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string s)
    {
        int n = s.length();
        int idx = 0;
        return helper2(idx, n, s);
    }
};
