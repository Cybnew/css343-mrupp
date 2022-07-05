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
    bool isValidBST(TreeNode* root) {
        TreeNode* ptr = nullptr;
        return helper( root, ptr);
    }

    bool helper(TreeNode* root, TreeNode*& ptr){
        if( root == nullptr ){
            return true;
        }
        //left recursive calls    
        if( helper(root->left, ptr) == false ){
            return false;
        } 
        if( ptr != nullptr && ptr->val >= root->val ){
          return false;  
        } 
        
        ptr = root;
        //right recursive calls
        return helper( root->right, ptr);
    }
};
