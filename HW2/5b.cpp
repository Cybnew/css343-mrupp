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
    void flatten(TreeNode* root) {
        //Base Case
        if(root == nullptr){
            return;
        }
        
        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        
        root->left = nullptr;
        //Recursive Calls
        flatten(leftChild);
        flatten(rightChild);
        
        root->right = leftChild;
        
        TreeNode* ptr = root;
        //Walk the right side
        while(ptr->right != nullptr){
            ptr = ptr->right;
        }
        //Set the right child of the ptr
        ptr->right = rightChild;
    }
};
