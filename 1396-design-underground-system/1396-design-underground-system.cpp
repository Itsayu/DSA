class UndergroundSystem {
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& [startStation, startTime] = checkInData[id];
        string route = startStation + "_" + stationName;
        travelTimes[route].first += t - startTime;
        travelTimes[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto& [totalTime, numTrips] = travelTimes[route];
        return (double)totalTime / numTrips;
    }
private:
    unordered_map<int, pair<string, int>> checkInData;
    unordered_map<string, pair<int, int>> travelTimes;
    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */