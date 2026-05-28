class Solution {
public:

struct trieNode{
    trieNode* child[26];
    bool isend;
};

trieNode* getNode(){
trieNode* newNode = new trieNode();
newNode->isend=false;
for(int i =0;i<26;i++) newNode->child[i]=NULL;
return newNode;
}

void insert(trieNode*root,string w){
    trieNode*node = root;
    for(char ch:w){
        int idx =ch-'a';
        if(node->child[idx]==NULL){
            node->child[idx] = getNode();
        }
        node= node->child[idx];
    }
    node->isend = true;
}
string  search(trieNode*root,string w){
    trieNode*node = root;
    for(int i =0;i<w.size();i++){
        int idx =w[i]-'a';
        if(node->child[idx]==NULL){
            return w;
        }
        node= node->child[idx];
    
    if(node->isend){
        return w.substr(0,i+1);
    }
    }
    return w;
}
    string replaceWords(vector<string>& dict, string sentence) {
    trieNode* root = getNode();
    for(auto word:dict) insert(root,word);

    stringstream ss(sentence);
    string word;
    string res;
    while(getline(ss,word,' ')){
        res+=search(root,word)+" ";
    }
    res.pop_back();
    return res;

    }
};