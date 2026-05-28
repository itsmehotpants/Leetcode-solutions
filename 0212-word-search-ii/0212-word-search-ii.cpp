

class Solution {
public:
vector<string>res;
int m,n;

struct trieNode{
bool isend;
string word;
trieNode* child[26];
};
trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode->isend =false;
    newNode->word="";
    for(int i=0;i<26;i++){
        newNode->child[i]=NULL;
    }
    return newNode;
}
void insert(trieNode* root,string& word){
    trieNode*node=root;
    for(int i =0;i<word.size();i++){
        char ch = word[i];
        int idx= ch-'a';
        if(node->child[idx]==NULL){
            node->child[idx]=getNode();
        }
        node=node->child[idx];

    }
    node->isend=true;
    node->word=word;
}
    
vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};//l,r,u,d

void findWord(vector<vector<char>>& board,int i ,int j, trieNode*root){
    if(i<0 ||j<0||i>=m||j>=n) return;
    if(board[i][j]=='$' ||root->child[board[i][j]-'a']==NULL) return;

    root = root->child[board[i][j]-'a'];
    if(root->isend==true){
        res.push_back(root->word);
        root->isend=false;
    }
    char temp =board[i][j];
    board[i][j]='$';

    for(vector<int>& d:dir){
        int new_i = i+d[0];
        int new_j = j+d[1];
        findWord(board,new_i,new_j,root);
    }
    board[i][j]=temp;
    
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m= board.size(),n=board[0].size();
        trieNode*root =getNode();

        for(string &word:words) insert(root,word);
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                   char ch =board[i][j];
                    if(root->child[ch-'a']!=NULL){
                        findWord(board,i,j,root);
                    }
            }
        }
        return res;
    }
};