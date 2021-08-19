# 1339. Maximum Product of Splitted Binary Tree

+ 要計算出一條edge左右兩棵樹相乘的最大值，必須先計算出整棵樹的總和 total_v

+ 如果目前在 node N
	+ 算出 sum( node->left ) * (total-sum( node->left ))
	+ 算出 sum( node->right ) * (total-sum( node->right ))
	+ 看能否更新最大值

```c++
class Solution {
public:
    
    long  max_v=0;   
    long total_v =0;   
    bool first=true;
    
    int maxProduct(TreeNode* root) {      
             
        total_v = dfs(root);
        
        first=false;
        
        dfs(root);
           
        return max_v % (int)(1e9 + 7);
        
    }
    
    int dfs(  TreeNode* root   ){
        
        if (root==NULL) return 0;

        int left_v = dfs(root->left);
        
        int right_v = dfs(root->right );
        
        if (!first) max_v =  max( max_v ,  max( (total_v - right_v) * right_v ,  (total_v - left_v) * left_v   ))   ;
        
        return root->val + left_v + right_v;
    }
       
};
```


