class Trie {
        public:
        Trie * alp[26];
        int isEnd;
        Trie() {
            for(int i=0;i<26;i++) {
                this->alp[i] = NULL;
            }
            this->isEnd = 0;
        }
};
class Solution {
public:
    int dfs(Trie* root, string& word, int j) {
        Trie *curr = root;
        int n = word.length();
        for(;j<n;j++) {
            if(curr->alp[word[j] - 'a'] == NULL) {
                return false;
            }
            curr = curr->alp[word[j] - 'a'];
            if(curr->isEnd && ((j==n-1) || dfs(root, word, j+1))) {
                return true;
            }
        }
        return false;
    }
    void insert(Trie *root, string& word) {
        if(word.length() == 0) return;
        for(int i=0;i<word.length();i++) {
            if(root->alp[word[i] - 'a'] == NULL) {
                root->alp[word[i] - 'a'] = new Trie();
            }
            root = root->alp[word[i]-'a'];
        }
        root->isEnd = 1;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        if(n == 0) return {};
        sort(words.begin(), words.end(), [](string& a, string& b)->bool{return a.size()<b.size();});
        Trie *root = new Trie();
        vector<string> result;
        for(int i=0;i<n;i++) {
            if(dfs(root, words[i], 0)) {
                result.push_back(words[i]);
            } else {
                insert(root, words[i]);
            }
        }
        return result;
    }
};
