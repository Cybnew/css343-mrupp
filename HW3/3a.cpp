class Solution {
    //map for storing visited nodes
    map<Node*, Node*> visited;
    Node* depthFirst(Node* node) {
        if(node == NULL) {
            return node;
        }
        // if the node is already in visited, return that node
        if(visited.find(node) != visited.end()) return visited[node];
        
        // make a new node and copy the value
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        
        //iterate through neighbors
        for(Node* edges: node->neighbors) {
            cloneNode->neighbors.push_back(depthFirst(edges));
        }
        return cloneNode;
    }
public:
    Node* cloneGraph(Node* node) {
        Node* clone = depthFirst(node);
        return clone;
    }
};
