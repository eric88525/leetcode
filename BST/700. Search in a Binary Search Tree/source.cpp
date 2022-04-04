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

// solution 1

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        if (root == NULL)
        {
            return NULL;
        }

        if (root->val == val)
            return root;

        else if (root->val > val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};

// solution 2

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        // right side
        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            root->left = insertIntoBST(root->left, val);
        }

        return root;
    }
};