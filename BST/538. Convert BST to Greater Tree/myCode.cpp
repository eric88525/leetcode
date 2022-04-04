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

// 這方法有夠爛 我自己寫的

class Solution
{
public:
    int sumNodes(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int sum = root->val;

        if (root->right != NULL)
            sum += sumNodes(root->right);

        if (root->left != NULL)
            sum += sumNodes(root->left);

        return sum;
    }

    TreeNode *convertBST(TreeNode *root, int preVal = 0)
    {

        if (root == NULL)
            return root;

        root->val += preVal;

        if (root->right != NULL)
        {

            // 點的數值需加上右半部的合
            root->val += sumNodes(root->right);

            // 然後往右走 並且需+前一個節點繼承的數值  preVal
            convertBST(root->right, preVal);
        }

        if (root->left != NULL)
        {
            // 往左走
            convertBST(root->left, root->val);
        }

        return root;
    }
};