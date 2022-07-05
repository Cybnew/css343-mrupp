//Node class
class Node {
public:
    
    bool isWord;
    Node *leaves[26];
    
    Node() {
        isWord = false;
        
        for (int i = 0; i < 26; i++)
            leaves[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
   //iterate through string 
    void insert(string word) {
        int length = word.length();
        Node * tmp = root;
        for(int i = 0;i < length;i++){
          //97 is ascii character value;
            int j = word[i] - 97;
            if(tmp->leaves[j] == NULL){
                tmp->leaves[j] = new Node();
            }
            tmp = tmp->leaves[j];
        }
        //set the boolean value to true
        tmp->isWord = true;
    }
    
    bool search(string word) {
        Node *tmp = root;
        int length = word.length();
        for(int i = 0;i < length ;i++){
            int j = word[i] - 'a';
            if(tmp->leaves[j] == NULL)
                return false;
            tmp = tmp->leaves[j];
        }
        
        if(tmp->isWord){
            return true;
        }
        
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *tmp = root;
        int length = prefix.length();
        for(int i = 0;i < length ;i++){
            int j = prefix[i] - 'a';
            if(tmp->leaves[j] == NULL)
                return false;
            tmp = tmp->leaves[j];
        }
        
        return true;
    }
    
    ~Trie() {
        clear(root);
    }

    Node *root;
    void clear(Node *tmp)
    {
        for(int i = 0;i < 26;i++)
        {
            if(tmp->leaves[i]){
                clear(tmp->leaves[i]);
            }
        }
        delete tmp;
    }
        
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
