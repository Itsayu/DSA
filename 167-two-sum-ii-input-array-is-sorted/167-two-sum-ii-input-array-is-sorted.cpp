class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s=0,ayu=numbers.size()-1;
    
    while(s<ayu){
        if(numbers[s]+numbers[ayu]>target){
            ayu--;
        }
        else if(numbers[s]+numbers[ayu]<target){
            int i=s;
            while(i<ayu){
                if(numbers[i]+numbers[ayu]>target)
                    break;
                else if(numbers[i]+numbers[ayu]<target)
                    i++;
                else
                    return{i+1,ayu+1};
            }
            ayu--;
        }
        else
            return{s+1,ayu+1};
    }
    return{-1,-1};
    }
};
