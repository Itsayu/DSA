class TrieNode{
public:
    TrieNode* child[26];
    bool is_word;
    string word;
    
    TrieNode(){
        for(int i=0;i<26;i++)
            child[i] = 0;
        is_word = false;
        word = "";
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(vector<string> &words){
        root = new TrieNode();
        for(auto s : words)
            insert(s);
    }
    
    TrieNode* getRoot(){
        return root;
    }
    
    void insert(string key){
        TrieNode* p = root;
        for(int i=0;i<key.length();i++){
            if(p->child[key[i]-'a'] == NULL)
                p->child[key[i]-'a'] = new TrieNode();
            p = p->child[key[i]-'a'];
        }
        p->is_word = true;
        p->word = key;
    }
};

class Solution {
public:
    vector<string> res;
    int m,n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        Trie trie(words);
        TrieNode* root = trie.getRoot();
            
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                backtrack(board,trie,root,i,j);
            }
        }
        
        return res;
    }
    
    void backtrack(vector<vector<char>>& board,Trie &trie,TrieNode* root,int row,int col){        
        if(row>m-1 || row<0 || col>n-1 || col<0 || board[row][col]=='*')
            return;

        char ch = board[row][col];
        if(root->child[ch-'a'] == NULL)
            return;
        
        root = root->child[ch-'a'];
        if(root->is_word != NULL){
            res.push_back(root->word);
            root->is_word = false;
        }
            
        board[row][col] = '*';
        
        backtrack(board,trie,root,row,col+1);
        backtrack(board,trie,root,row+1,col);
        backtrack(board,trie,root,row,col-1);
        backtrack(board,trie,root,row-1,col);
        
        board[row][col] = ch;
        
        return;
        
    }
};