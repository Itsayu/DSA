class Solution {
public:
    string predictPartyVictory(string senate) {
        int rc = 0, dc = 0;
        for (char c : senate) c == 'R' ? rc++ : dc++;
        int rk = 0, dk = 0;
        int i = 0, n = senate.size();
        while (rc > 0 && dc > 0) {
            if (senate[i] == '*');
            else if (senate[i] == 'R' && rk > 0) { rk--; senate[i] = '*'; rc--;}
            else if (senate[i] == 'D' && dk > 0) { dk--; senate[i] = '*'; dc--;}
            else {senate[i] == 'R' ? dk++ : rk++;}
            i = (i+1)%n;
        }
        return rc > 0 ? "Radiant" : "Dire";
    }
};