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