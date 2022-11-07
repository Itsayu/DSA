class Solution {
public:
    int maximum69Number (int num) {
        string nr = to_string(num); //converting int to string, coz dealing in string is easier
        
        for(int i=0; i<nr.size(); i++){
            if(nr.at(i)=='6'){
                nr.at(i)='9';
                break;
            }
        }
        return stoi(nr);
    }
};