class Trie {
private:
    class Node {
    public:
        vector<Node*> children;
        bool isLeaf;

        Node(){
            children.resize(26,NULL);
            isLeaf = false;
        }
    };
public:
    
    Node *main;

    Trie() {
        main = new Node();
    }
    
    Node* walk(string word){
        Node *root = main;
        for(auto letter : word){
            int indexLetter = letter - 'a';
            if(!root->children[indexLetter])
                return NULL;
            root = root->children[indexLetter]; 
        }
        return root;
    }
    
    void insert(string word) {
        Node *root = main;
        for(auto letter : word){
            int indexLetter = letter - 'a';
            if(!root->children[indexLetter])
                root->children[indexLetter] = new Node();
            root = root->children[indexLetter]; 
        }
        root->isLeaf = true;
    }
    
    bool search(string word) {
        Node *node = walk(word);
        return (node != NULL and node->isLeaf);
    }
    
    bool startsWith(string prefix) {
        Node *node = walk(prefix);
        return node != NULL;
    }
};