# 106. Construct Binary Tree from Inorder and Postorder Traversal

## about inoder and postorder

https://shubo.io/iterative-binary-tree-traversal/

http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html

## idea

- postorder 順序為 左-右-中，root 點會在陣列中最後的位置
- 我們可以透過把 postorder 從後面往前取，依序取得 中-右-左 subTree 的 root 節點
- inorder 順序為左-右-中，可以用來判斷甚麼時候樹該停止擴展

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
        // 取得中間節點在 inorder 的 index
        int midRoot = rootIndex[  postorder[postIndex] ];
        // 透過 postorder　取得 root 數值
        TreeNode* root = new TreeNode( postorder[postIndex--] );
        // create right tree by mid+1 to end
        root->right = solve( inorder, postorder ,  midRoot+1 , end  , postIndex  );
        // create left tree by start to mid-1
        root->left = solve( inorder, postorder ,  start  , midRoot-1  , postIndex  );

        return root;
    }
};
```
