class Solution {
public:   
    
    int sum;  
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        if(!root) return 0;
        
        if (root->val <= high && root->val >= low) {
           sum += root->val ;    
        }                 
        
        if(root->right  && root->val < high ) rangeSumBST( root->right ,  low,  high);                 
        if(root->left && root->val > low )  rangeSumBST( root->left ,  low,  high);                
       
        return sum;
    }
};