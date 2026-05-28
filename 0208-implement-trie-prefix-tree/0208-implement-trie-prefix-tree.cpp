class Trie {
public:
        bool isend=0;
        Trie* child[26];
  
        
        Trie() {
            isend=false;
            for(int i =0;i<26;i++) child[i]=NULL;
        }
    
    
    void insert(string word) {
        Trie* node = this;
        for(char ch:word){
            int idx = ch-'a';
            if(node->child[idx]==NULL){
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
        }
        node->isend=1;
    }

    
    bool search(string word) {
        Trie* node = this;
        for(char ch:word){
            int idx = ch-'a';
            if(node->child[idx]==NULL){
               return false;
            }
            node = node->child[idx];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
         Trie* node = this;
        for(char ch:prefix){
            int idx = ch-'a';
            if(node->child[idx]==NULL){
               return false;
            }
            node = node->child[idx];
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