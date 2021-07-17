# 701. Insert into a Binary Search Tree

有兩種解法，一種是透過迴圈 另一種是透過遞迴

https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

### loop

Create 2 pointer,one is point to previous node and the other is point to current node.
let current pointer find place to insert node. 

+ If val  < current node's val , let current node point to current node's left place.
+ If val  > current node's val , let current node point to current node's left place.

+ Insert new node to temp node's left or right.

### Recursion

```c++
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
             
        // right side
        if(root->val < val  ){
            root->right =  insertIntoBST(root->right , val);
        }else{
            root->left = insertIntoBST(root->left , val);
        }
        
        return root;
        
    }
```

