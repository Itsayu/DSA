class TrieNode {
public:
	char c;
	unordered_map<char, TrieNode*> children;
	int count;

	TrieNode(char ch) { 
        c = ch;
        count = 0; // no of strings that have root to this node as their prefix
    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode('*');
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char ch : word) {
            if(cur -> children.find(ch) == cur -> children.end()) {
                cur -> children[ch] = new TrieNode(ch);
            }
            
            cur = cur -> children[ch];
            cur -> count += 1;
        }
    }

    int getScore(string word) {
        TrieNode* cur = root;
        int score = 0;
        for(char ch : word) {
            cur = cur -> children[ch];
            score += cur -> count;
        }
        return score;
    }

};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* t = new Trie();
        for(string word: words) {
            t -> insert(word);
        }
        
        vector<int> answer;
        for(string word: words) {
            answer.push_back(t -> getScore(word));
        }
        
        return answer;
    }
};
