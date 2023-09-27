class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        int n = s.size();
		   // Calculate the size of the decoded string
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                size *= s[i] - '0';
               
            } else {
                size++;
            }
        }
        //cout<<size<<endl;   total number of charactor in main string 
		
      // Start decoding from the end of the string
        for (int i = n - 1; i >= 0; i--) {
            k =k% size; 

            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);  //If k becomes 0, then we found the charactor.
            }
            if (isdigit(s[i])) {
                size /= s[i] - '0';
            } else {
                size--;
            }
        }

        return "";
    }
};