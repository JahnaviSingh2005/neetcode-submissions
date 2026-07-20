struct TrieNode {
    TrieNode* children[26] = {};
    bool isWord = false;
};

class WordDictionary {
    TrieNode root;

public:
    WordDictionary() {}

    void addWord(string word) {
        TrieNode* cur = &root;
        for (char c : word) {
            if (!cur->children[c - 'a']) 
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, &root);
    }

private:
    bool dfs(const string& word, int idx, TrieNode* node) {
        if (!node) return false;
        if (idx == word.size()) return node->isWord;

        if (word[idx] != '.') {
            return dfs(word, idx + 1, node->children[word[idx] - 'a']);
        }

        for (auto child : node->children) {
            if (child && dfs(word, idx + 1, child)) return true;
        }
        return false;
    }
};