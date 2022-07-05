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
   
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty()){    
            return nullptr;
        }   
       //The root node
        int postRoot = postorder.size()-1;		
       //construct a new tree with the root value at our postOrder index 
        TreeNode *tree = new TreeNode(postorder[postRoot]);		
        int i;
        int sz=inorder.size();:
        for(i=0; i<sz; i++)  	
            if(inorder[i]==postorder[postRoot]){
                break;
            } 
        //Construct subvector        
        vector<int> leftPost(postorder.begin(),postorder.begin()+i);
        
        vector<int> rightPost(postorder.begin()+i,postorder.end()-1);
        
        vector<int> leftInorder(inorder.begin(),inorder.begin()+i);
        vector<int> rightInorder(inorder.begin()+i+1,inorder.end());
        
        //recurse down left half
        tree->left = buildTree(leftInorder,leftPost);
        //recurse down right half
        tree->right = buildTree(rightInorder,rightPost);
        
        return tree;
    }

};
