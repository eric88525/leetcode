# 106.  Construct Binary Tree from Inorder and Postorder Traversal

## about inoder and postorder 

https://shubo.io/iterative-binary-tree-traversal/ 

## idea

+ the last element of postorder contains main root node

+ create tree by root node & change the range of onorder when go to next step of recursion

```c++
class Solution {
public:
    
    map<int,int> rootIndex;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for(int i=0;i<inorder.size();i++){
            rootIndex[inorder[i]] = i; 
        }
        
        int n = inorder.size() -1 ;
        auto ans = solve(  inorder, postorder ,0, n,n );
        
        return ans;
        
    }
    
    
    TreeNode * solve(  vector<int>& inorder, vector<int>& postorder , int start , int end , int &postIndex  ){
        
        if (start > end ) return NULL;
        
        int midRoot = rootIndex[  postorder[postIndex] ];
        
        postIndex--;
        
        TreeNode* root = new TreeNode( inorder[midRoot] );
        
        // create right tree by mid+1 to end
        root->right = solve( inorder, postorder ,  midRoot+1 , end  , postIndex  );
        // create left tree by start to mid-1    
        root->left = solve( inorder, postorder ,  start  , midRoot-1  , postIndex  );
             
        return root;
        
    }

    
};
```



