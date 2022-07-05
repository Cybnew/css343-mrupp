/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//Begin Solution
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
       
        //Tracker for size
        int sz;
        
        queue<Node*> q;

        //Enqueue the root node pointer
        q.push(root);
        

        while(!q.empty()){
            sz = q.size();
            
            //for loop for traversing across the level items
            for(int i = 0; i< sz; i++){;
                Node* cur = q.front();
                
                if(cur->left != nullptr){
                    //enqueue left subtree
                    q.push(cur->left);
                }
                //enqueue right subtree
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
                //remove the next item
                q.pop();
                if(i < sz - 1){
                    //set the next current node pointer from the queue
                    cur->next = q.front();
            }
        }
        
    }
        return root;
        }
};
