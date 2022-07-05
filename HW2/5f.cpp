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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        //base case
        if(root->val == key){
            if(root->left == nullptr){
                return root->right;
            }
            if(root->right == nullptr){
                return root->left;
            }
            //temp node for finding inorder successor
            TreeNode* tmp;
            tmp = root->right;
            while(tmp->left != nullptr){
                tmp = tmp->left;
            }
            root->right = deleteNode(root->right,tmp->val);
            tmp->left = root->left;
            tmp->right = root->right;
            root = tmp;
        //move left
        } else if (root->val > key){
            root->left = deleteNode(root->left,key);
            
        //move right
        } else {
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
    
};
