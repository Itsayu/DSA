class Solution {
public:
    bool isPowerOfTwo(int i) {
        if (i > 0) {
            while (i % 2 == 0) {
                i = i / 2;
            }
        if (i == 1) {
            return i;
        } 
    } 
    return 0;  
    }
};