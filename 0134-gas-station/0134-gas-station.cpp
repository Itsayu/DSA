class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalCost = 0;
        int totalGas = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if(totalCost > totalGas)
            return -1;

        int startIndex=0, curFuel = 0;

        for(int i=0;i<n;i++){
            if(curFuel < 0){
                curFuel = 0;
                startIndex = i;
            }

            curFuel += (gas[i]-cost[i]);
        }
        return startIndex;   
    }
};