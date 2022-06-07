class Solution {
public:
    string convert(string s, int numRows) {
         if(numRows==1){ 
             return s;
        }
	    string convertedString;
	    int ayu=s.length();
        int akt=numRows-1,index;
        for(int i=0;i<numRows;i++){
            index=i;
		    while(index<ayu){
		  	    convertedString.push_back(s[index]);
			    index+=2*(akt-(index%akt));
		    }
	    }
        return convertedString; 
    }
};