class Node{
public:
    char ch;
    map<char, Node*>mp;
    bool isTerminal;
    Node(char d){
        this->ch = d;
        this->isTerminal = false;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node(' ');
    }
    
    void insert(string word) {
        Node *temp = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            if(temp->mp.count(ch) == 0){
                Node *n = new Node(ch);
                temp->mp[ch] = n;
            }
            temp = temp->mp[ch];
        }
        temp->isTerminal = true;
    }
    bool search(string word) {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->mp.count(word[i]) == 0)
            {
                return false;
            }
            temp = temp->mp[word[i]];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (temp->mp.count(prefix[i]) == 0)
            {
                return false;
            }
            temp = temp->mp[prefix[i]];
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
