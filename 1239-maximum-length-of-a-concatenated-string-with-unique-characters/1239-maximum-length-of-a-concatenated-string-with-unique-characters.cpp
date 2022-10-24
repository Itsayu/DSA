class Solution {
public:
    int maxLength(vector<string>& arr) {
        int N = arr.size();
        int ans = 0;
        vector<int> wrongMask;
		
        for(int mask = 0; mask < (1 << N); mask++) {
            
            bool notPossible = false;
            for(auto a : wrongMask) {
                if(__builtin_popcount(mask & a) > 1) {
                    notPossible = true;
                    break;
                } 
            }
            
            if(notPossible) continue;
            
            unordered_map<char, int> M;
            for(int i = 0; i < N; i++) {
                if(mask >> i & 1) {
                    for(char c : arr[i]) {
                        if(M.count(c)) {
							// If map contains a duplicate character, push this mask in wrongMask
							// then directly jump to next mask.
                            wrongMask.push_back(mask);
                            goto nextMask;
                        }
                        M[c]++;
                    }
                }
            }
            ans = max(ans,(int)M.size());
            nextMask:;
            
        }
        return ans;    
    }
};