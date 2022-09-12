class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size()-1;
        int points = 0, maxpoints = 0;
        
        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left];
                points++; left++;
            }
            else{
                if(points){
                    points--;
                    power += tokens[right];
                    right--;
                }
                else{
                    break;
                }
            }
            maxpoints = max(maxpoints, points);
        }
        return maxpoints;    
    }
};