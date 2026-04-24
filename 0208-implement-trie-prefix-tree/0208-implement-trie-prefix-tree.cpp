class Trie {
public:
    struct Node {
        Node* links[26];
        bool flag;
        Node() {
            for(int i=0;i<26;i++) links[i]=NULL;
            flag=false;
        }
    };
    
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!node->links[idx]) node->links[idx] = new Node();
            node = node->links[idx];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!node->links[idx]) return false;
            node = node->links[idx];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(!node->links[idx]) return false;
            node = node->links[idx];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */