# 538. Convert BST to Greater Tree

https://leetcode.com/problems/convert-bst-to-greater-tree/discuss/1057416/C%2B%2B-or-Reverse-Inorder-Traversal-or-O(n)-0ms-Beats-100-or-Explanation

## 大神寫法

The **right-most node** is the maximum value in tree,we need to process it first and then go left nodes.

Process:

1. set currentSum = 0 , it means the sum of nodes which value is bigger than currentNode
2. let currentNode += currnetSum and update currentSum
3. go process left node

```c++
class Solution {
public:

    int currentSum=0;

    void go( TreeNode* root  ){

        if(root->right) go(root->right);

        currentSum += root->val;
        root-> val =currentSum;

        if(root->left) go(root->left);

    }


    TreeNode* convertBST(TreeNode* root) {

        if(!root) return root;

        go(root);

        return root ;
    }
};
```
