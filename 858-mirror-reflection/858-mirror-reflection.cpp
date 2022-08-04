class Solution {
public:
    int mirrorReflection(int p, int q) {
        int height = q;
        int new_height;
        bool reflections = 0;
        
        int bounce = 1;    // 1 = up, -1 = down
        
        while (height != 0 && height != p) {
            reflections = !reflections;  // switch even / odd count of reflections
            new_height = height + (q * bounce);
            if (new_height > p) {
                new_height = p - (q - (p - height));
                bounce = -bounce;
            }
            else if (new_height < 0) {
                new_height = 0 + (q - height);
                bounce = -bounce;
            }
            height = new_height;
        }
        
        if (height == 0) {
            return 0;
        }
        return (reflections) ? 2 : 1;
    }
};