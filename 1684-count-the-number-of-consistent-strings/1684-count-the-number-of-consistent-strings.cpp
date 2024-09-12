class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set to store allowed characters
        set<char> st;
        for (char ch : allowed) {
            st.insert(ch);
        }

        // Initialize count of consistent strings
        int count = 0;

        // Iterate over each word
        for (const string& word : words) {
            bool isAllowed = true;

            // Check if all characters of the word are in the set
            for (char ch : word) {
                if (st.find(ch) == st.end()) {
                    isAllowed = false;
                    break;
                }
            }

            // Increment count if the word is consistent
            if (isAllowed) {
                count++;
            }
        }

        return count;
    }
};