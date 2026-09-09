// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
public:
    struct trieNode{
        trieNode *children[26];
        bool isEndOfWord;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        for(int i=0; i<26; i++) newNode->children[i] = NULL;
        return newNode;
    }

    trieNode *root;

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';
            if(!crawler->children[index]) crawler->children[index] = getNode();
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true;
    }
    
    bool searchUtil(trieNode* root, string word){
        trieNode* crawler = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!crawler->children[ch-'a']) return false;
            crawler = crawler->children[ch-'a'];
        }
        return (crawler!=NULL && crawler->isEndOfWord == true);
    }

    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for(char ch: prefix) {
            if(!crawler->children[ch - 'a']) return false;
            crawler = crawler->children[ch - 'a'];
        }
        return true;
    }
};