class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       vector<vector<int>> groupsOfPeople;

        map<int, vector<int>> groupMap;

        for (int personID = 0; personID < groupSizes.size(); personID++) {
            int desiredGroupSize = groupSizes[personID];
       groupMap[desiredGroupSize].push_back(personID);

            if (groupMap[desiredGroupSize].size() == desiredGroupSize) {
                   groupsOfPeople.emplace_back(move(groupMap[desiredGroupSize]));
               groupMap[desiredGroupSize].clear();
            }
        }

  
        return groupsOfPeople;
    }
};