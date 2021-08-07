
// BFS VERSION
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        
        
        if(!root) return vector<vector<int>>();
        
        queue<Node*> nodeList;        
        nodeList.push(root);
         
        vector<vector<int>> ans;
        
        while( !nodeList.empty()  ){
            
            vector<int> curr;
           
            int s = nodeList.size();
            
            for(int i=0;i<s;i++ ){
                
                Node* temp = nodeList.front();
                nodeList.pop();
                
                for(auto n:temp->children){
                    nodeList.push(n);
                }
                curr.push_back(temp->val);
            }
            
            ans.push_back(curr);  
        }   
        return ans;
    }  
        
};

// Recursion


class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL) return vector<vector<int>>();
        
        ans.push_back( vector<int>({root->val}));
        
        go(root,2);
        
        return ans;
    }
    void go( Node* root  , int depth ){
               
        for(auto i:root->children){          
            if (depth > ans.size())  ans.push_back( vector<int>());
            ans[depth-1].push_back(i->val);
            go( i  , depth+1 );

        }
        
    } 
    
};
