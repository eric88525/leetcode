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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        TreeNode *n = new TreeNode(val);
        TreeNode *p = root;
        TreeNode *prev = NULL;

        if (root == NULL)
            return n;

        while (p)
        {
            if (p->val < val)
            {
                prev = p;
                p = p->right;
            }
            else if (p->val > val)
            {
                prev = p;
                p = p->left;
            }
        }
        if (prev->val < val)
        {
            prev->right = n;
        }
        else
        {
            prev->left = n;
        }
        return root;
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