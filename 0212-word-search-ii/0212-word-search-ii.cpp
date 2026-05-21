class TrieNode {
public:
    TrieNode* children[26];
    string word;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* curr = root;
            for (char c : w) {
                int index = c - 'a';
                if (!curr->children[index]) {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->word = w;
        }
        
        vector<string> result;
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a']) {
            return;
        }
        
        p = p->children[c - 'a'];
        if (p->word != "") {
            result.push_back(p->word);
            p->word = ""; 
        }
        
        board[i][j] = '#';
        
        if (i > 0) dfs(board, i - 1, j, p, result);
        if (j > 0) dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, result);
        
        board[i][j] = c;
    }
};