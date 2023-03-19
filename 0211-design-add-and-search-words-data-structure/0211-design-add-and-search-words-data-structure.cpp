class WordDictionary {
public:
    WordDictionary() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        wordSet.resize(26);
    }
    
    void addWord(string word) {
        int len=word.size();
        
        wordSet[len].insert(word);
    }
    
    bool search(string word) {
        int len=word.size();
        
        if(word.find('.')==string::npos){
            return wordSet[len].count(word)>0;
        }
        
        for(auto &wrd: wordSet[len]){
            bool match{true};
            
            for(int i=0;i<len;++i){
                if(word[i]=='.') continue;
                if(word[i]!=wrd[i]){
                    match=false;
                    break;
                }
            }
            if(match) return true;
        }
        return false;
    }
private : vector<unordered_set<string>> wordSet;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */