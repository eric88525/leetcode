# 543. Diameter of Binary Tree


對每個節點去檢視，往左探索的最深和往右探索的最深是否有最大值

For each node, the diameter is the height of the left node + the height of the right node.
So we use DFS to get the heights recursively, and keep in `diameter` the maximum seen.

```c++
class Solution {
public:    
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
             
        ans = 0;
        depth(root);       
        return ans;
        
    }
 
    int depth(TreeNode* root ){
       
        if(!root) return 0;     
        int left = depth(root->left);
        int right = depth(root->right);
                
        ans = max(ans , left + right);
        return max(left,right) +1;             
    }
};
```

