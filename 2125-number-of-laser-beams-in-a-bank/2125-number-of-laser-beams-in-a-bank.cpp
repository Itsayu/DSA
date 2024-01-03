class Solution {
public:
    int numberOfBeams(vector<string>& bank){        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(bank.size() < 2)
            return 0;

        int solution = 0;
        short beaconsInPrevRow = 0;
        short beaconsInCurrentRow = 0;
        for(size_t i = 0; i < bank.size(); ++i){
            beaconsInCurrentRow = 0;

            for(auto &it : bank[i]){
                if(it == '1'){
                    beaconsInCurrentRow++;
                }
            }
            solution += beaconsInCurrentRow * beaconsInPrevRow;
            beaconsInPrevRow = (beaconsInCurrentRow == 0) * beaconsInPrevRow + beaconsInCurrentRow;
        }

        return solution;
 
    }
};