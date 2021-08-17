# 1448. Count Good Nodes in Binary Tree

+ If we want to check there's no greater node in the path from root,we need to pass the max value from the path to next recursion.
+ USE recursion

```c++
class Solution {
public:
      
    int ans;
    
    int goodNodes(TreeNode* root) {
        
        ans=0;
        
        dfs(root,INT_MIN);
             
        return ans;
    }
    
    void dfs( TreeNode* root , int max_value ){
        
        if( root->val >= max_value ){
            ans++;
            max_value = root->val;  
        } 
        if(root->left!=NULL){
            dfs(root->left, max_value );
        }
        if(root->right!=NULL){
            dfs(root->right, max_value);
        }          
    }
     
};
```
