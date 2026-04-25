class WordDictionary {
public:
    struct Node {
        Node* links[26];
        bool flag;
        Node() {
            for(int i = 0; i < 26; i++) links[i] = NULL;
            flag = false;
        }
    };
    
    Node* root;
    
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char c : word) {
            if(!node->links[c - 'a']) {
                node->links[c - 'a'] = new Node();
            }
            node = node->links[c - 'a'];
        }
        node->flag = true;
    }
    
    bool dfs(string &word, int index, Node* node) {
        if(index == word.size()) return node->flag;
        if(word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                if(node->links[i] && dfs(word, index + 1, node->links[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if(!node->links[word[index] - 'a']) return false;
            return dfs(word, index + 1, node->links[word[index] - 'a']);
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */