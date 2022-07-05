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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //if the root is null, create a new node with the value
         if (root == nullptr) {
             root = new TreeNode(val);
        } else {
             //otherwise, if the value is less than the current node value, move left
            if (val <= root->val) {
                root->left = insertIntoBST(root->left, val);
            // otherwise move right
            } else {
                root->right = insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};
