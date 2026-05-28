// class Trie {
// public:
//         bool isend=0;
//         Trie* child[26];
  
        
//         Trie() {
//             isend=false;
//             for(int i =0;i<26;i++) child[i]=NULL;
//         }
    
    
//     void insert(string word) {
//         Trie* node = this;
//         for(char ch:word){
//             int idx = ch-'a';
//             if(node->child[idx]==NULL){
//                 node->child[idx] = new Trie();
//             }
//             node = node->child[idx];
//         }
//         node->isend=1;
//     }

    
//     bool search(string word) {
//         Trie* node = this;
//         for(char ch:word){
//             int idx = ch-'a';
//             if(node->child[idx]==NULL){
//                return false;
//             }
//             node = node->child[idx];
//         }
//         return node->isend;
//     }
    
//     bool startsWith(string prefix) {
//          Trie* node = this;
//         for(char ch:prefix){
//             int idx = ch-'a';
//             if(node->child[idx]==NULL){
//                return false;
//             }
//             node = node->child[idx];
//         }
//         return true;
//     }
// };

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */


class Node{
    public:

    char data;
    unordered_map<char,Node*> m;
    bool isend;

    Node(char d){
        data =d;
        isend=false;
    }

};
class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node('\0');

    }
    void insert(string word){
        Node* temp =root;
        for(char ch:word){
            if(temp->m.count(ch)==0) {
                Node* n = new Node(ch);
                temp->m[ch]=n;

            }
            temp = temp->m[ch];

        }
        temp->isend=1;
    }
    bool search(string word){
            Node* temp =root;
        for(char ch:word){
            if(temp->m.count(ch)==0) {
                return false;
        
            }
            temp = temp->m[ch];

        }
       return temp->isend;
    }
    bool startsWith(string prefix){
         Node* temp =root;
        for(char ch:prefix){
            if(temp->m.count(ch)==0) {
                return false;

            }
            temp = temp->m[ch];

        }
       return true;
    }
};