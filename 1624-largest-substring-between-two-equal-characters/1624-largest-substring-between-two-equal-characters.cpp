class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxDistance = -1;

        // Iterate over all pairs of indices (left, right) in the string.
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                // Check if characters at indices left and right are equal.
                if (s[left] == s[right]) {
                    // Update the maximum distance between equal characters.
                    maxDistance = max(maxDistance, right - left - 1);
                }
            }
        }

        return maxDistance;
    }
};